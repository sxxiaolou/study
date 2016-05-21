local skynet = require "skynet"
local netpack = require "netpack"

--------------------hankai_start------------------------
local SceneHandler = require "module.scene.Handler"
local AuthCheck = require "module.scene.AuthCheck"
local CommonDefine = require "common.CommonDefine"
local Human = require "core.Human"
--------------------hankai_end-------------------------

local HKCMD = {}
local CMD = {}
local SOCKET = {}
local gate                                                                        ---网关
local agent = {}                                                                ---玩家
local address = {}                                                             ---登录的ip

function SOCKET.open(fd, addr)
	skynet.error("New client from : " .. addr)
	address[fd] = addr
	agent[fd] = skynet.newservice("agent")
	skynet.call(agent[fd], "lua", "start", { gate = gate, client = fd, watchdog = skynet.self() })
end

local function close_agent(fd)
	local a = agent[fd]
	agent[fd] = nil
	address[fd] = nil
	if a then
		skynet.call(gate, "lua", "kick", fd)
		-- disconnect never return
		skynet.send(a, "lua", "disconnect")
	end
end

function SOCKET.close(fd)
	print("socket close",fd)
	close_agent(fd)
end

function SOCKET.error(fd, msg)
	print("socket error",fd, msg)
	close_agent(fd)
end

function SOCKET.warning(fd, size)
	-- size K bytes havn't send out in fd
	print("socket warning", fd, size)
end

function SOCKET.data(fd, msg)
end

function CMD.start(conf)
	skynet.call(gate, "lua", "open" , conf)
end

function CMD.close(fd)
	close_agent(fd)
end

skynet.start(function()
	skynet.dispatch("lua", function(session, source, cmd, subcmd, ...)
		print("[:'log']--['file':watchdog.lua]--['fun':lua dispatch]",session,source,cmd,subcmd,...)
		if cmd == "socket" then
			local f = SOCKET[subcmd]
			f(...)
			-- socket api don't need return
		elseif HKCMD[cmd] then
			HKCMD[cmd](subcmd,...)
		else
			local f = assert(CMD[cmd])
			skynet.ret(skynet.pack(f(subcmd, ...)))
		end
	end)
	gate = skynet.newservice("hkgate")
end)

----------------------hk_start------------------------------------
function HKCMD.CG_ASK_LOGIN(lua_data)
	skynet.error("CG_ASK_LOGIN account: " .. lua_data.account, "client_fd:"..lua_data.client_fd)
	
	local onlienCnt = 0

	for k in pairs(agent) do
		onlienCnt = onlienCnt + 1
	end

	if onlienCnt > CommonDefine.MAX_ONLINE_COUNT then
		skynet.error("max online count ")
		--to do 发送断线消息
		close_agent(lua_data.client_fd)
		return
	end

	local account = lua_data.account
	local authkey = lua_data.authkey
	local client_fd = lua_data.client_fd

	local retAuth = AuthCheck.AuthCheck(account,authkey)
	if retAuth ~= true then
		--to do 发送认证失败消息
		return
	end

	lua_data.human_id = Human.id
	lua_data.addr = address[lua_data.client_fd]
	Human.id = Human.id + 1

	local human = skynet.call(lua_data.agent,"lua","create_human",lua_data)
	skynet.error("LOGIN success !")
end
----------------------hk_end--------------------------------------
