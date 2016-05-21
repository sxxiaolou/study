local skynet = require "skynet"
local netpack = require "netpack"
local socket = require "socket"

--------------------hankai_start------------------------

--------------------hankai_end-------------------------

local WATCHDOG
local host

local CMD = {}
local REQUEST = {}
local client_fd
local handler_id_by_name = handler_id_by_name or {}
local has_login = false --已经登录

function get_handler_id_by_name(name)
	local handler_id = handler_id_by_name[name]
	if handler_id == nil then
		handler_id = skynet.localname(name)
		handler_id_by_name[name] = handler_id
	end
	return handler_id
end

function REQUEST:get()
	print("get", self.what)
	local r = skynet.call("SIMPLEDB", "lua", "get", self.what)
	return { result = r }
end

function REQUEST:set()
	print("set", self.what, self.value)
	local r = skynet.call("SIMPLEDB", "lua", "set", self.what, self.value)
end

function REQUEST:quit()
	skynet.call(WATCHDOG, "lua", "close", client_fd)
end

local function request(name, args, response)
	local f = assert(REQUEST[name])
	local r = f(args)
	if response then
		return response(r)
	end
end

local function send_package(pack)
	-- print("[:'log']--['file':agent.lua]--['fun':send_package]--['pack:']",pack)
	local package = string.pack(">s2", pack)
	-- print("[:'log']--['file':agent.lua]--['fun':send_package]--['package:']",package)
	socket.write(client_fd, package)
end

skynet.register_protocol {
	name = "client",
	id = skynet.PTYPE_CLIENT,
	unpack = function (msg, sz)
		return msg, sz
	end,
	dispatch = function (_, _, data, size, ...)
		local res_msg = skynet.tostring(data,size)
		print("[:'log']--['file':agent.lua]--['fun':client dispatch]--['res_msg:']",res_msg,"--['size:']",size,"--['len:']",#res_msg)
		local protoid_high = string.byte(res_msg,1)
		local protoid_low = string.byte(res_msg,2)
		print("[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid_high:']",protoid_high,"--['protoid_low']",protoid_low)
		local protoid = tonumber(protoid_high) << 8 | protoid_low
		local msgdata = string.sub(res_msg,3,size)
		print("[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid:']",protoid,#msgdata)
		local handler_id = get_handler_id_by_name(".msgservice")
		print("[:'log']--['file':agent.lua]--['fun':client dispatch]--['handler_id:']",handler_id)
		--解析数据
		local lua_data = skynet.call(handler_id,"lua","PARES_CG",protoid,msgdata)
		if lua_data ~= nil then
			--lua_data.service
			--lua_data.service_fun
			--lua_data.client_fd 客户端连接
			--lua_data.agent
			lua_data.client_fd = client_fd
			lua_data.agent = skynet.self()
			if has_login ~= true then
				if lua_data.service == ".watchdog" then
					skynet.send(WATCHDOG,"lua",lua_data.service_fun,lua_data)
				else
					print("plese login game!")
					return
				end
			end

			-- if lua_data.service == ".agent" then
			-- 	local ret_data = {}
			-- 	ret_data.protoid = 590
			-- 	ret_data.account = "skynet"
			-- 	ret_data.obj_id = 0
			-- 	ret_data.x = -1
			-- 	ret_data.y = -2147483648
			-- 	ret_data.points = {10000,888888,99999,1000000,777777777,2147483647}
			-- 	ret_data.testdouble = {140737488355328,-140737488355329,54887884878,1,-1,0}
			-- 	CMD["send_client"](ret_data)
			
			-- end
		end
	end
}

function CMD.start(conf)
	local fd = conf.client
	local gate = conf.gate
	WATCHDOG = conf.watchdog

	-- skynet.fork(function()
	-- 	while true do
	-- 		send_package("Welcome to skynet, I will send heartbeat every 5 sec.")
	-- 		skynet.sleep(500)
	-- 	end
	-- end)

	client_fd = fd
	skynet.call(gate, "lua", "forward", fd)
end

function CMD.disconnect()
	-- todo: do something before exit
	skynet.exit()
end

function CMD.send_client(lua_data)
	local msgservice_id = handler_id_by_name[".msgservice"]
	if msgservice_id == nil then
		msgservice_id = skynet.localname(".msgservice")
		handler_id_by_name[".msgservice"] = msgservice_id
	end

	local str_data = skynet.call(msgservice_id,"lua","PARES_GC",lua_data.protoid,lua_data)

	if str_data ~= "" then
		print("[:'log']--['file':agent.lua]--['fun':send_client]",#str_data)
		send_package(str_data)
	else
		print("[:'log']--['file':agent.lua]--['fun':send_client]","   str_data == nil")
	end
end

------------------------------hankai_start----------------------------------------
function CMD.create_human(lua_data)
	print("[:'log']--['file':agent.lua]--['fun':create_human] start")
	local human = {}
	human.client_fd = lua_data.client_fd
	human.id = lua_data.human_id

	local handler_id = get_handler_id_by_name(".dbservice")
	local db_data = skynet.call(handler_id,"lua","loadRole",lua_data)
	

	print("[:'log']--['file':agent.lua]--['fun':create_human] end")
end
------------------------------hankai_end-----------------------------------------

skynet.start(function()
	skynet.dispatch("lua", function(_,_, command, ...)
		local f = CMD[command]
		skynet.ret(skynet.pack(f(...)))
	end)
end)
