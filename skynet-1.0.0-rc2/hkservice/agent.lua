local skynet = require "skynet"
local netpack = require "netpack"
local socket = require "socket"



local WATCHDOG
local host

local CMD = {}
local REQUEST = {}
local client_fd
local handler_id_by_name = handler_id_by_name or {}

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
		local handler_id = handler_id_by_name[".msgservice"]
		if handler_id == nil then
			handler_id = skynet.localname(".msgservice")
			handler_id_by_name[".msgservice"] = handler_id
		end
		print("[:'log']--['file':agent.lua]--['fun':client dispatch]--['handler_id:']",handler_id)
		local lua_data = skynet.call(handler_id,"lua","PARES_CG",protoid,msgdata)
		if lua_data ~= nil then
			if lua_data.service == ".agent" then
				lua_data.protoid = 590
				CMD["send_client"](lua_data)
			-- elseif then
			-- else
			end
		end
	end
}

function CMD.start(conf)
	local fd = conf.client
	local gate = conf.gate
	WATCHDOG = conf.watchdog

	skynet.fork(function()
		while true do
			send_package("Welcome to skynet, I will send heartbeat every 5 sec.")
			skynet.sleep(500)
		end
	end)

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

	local str_data = skynet.call(handler_id,"lua","PARES_GC",lua_data.protoid,lua_data)

	if str_data ~= nil then
		send_package(str_data)
	else
		print("[:'log']--['file':agent.lua]--['fun':send_client]","   str_data == nil")
	end
end

skynet.start(function()
	skynet.dispatch("lua", function(_,_, command, ...)
		local f = CMD[command]
		skynet.ret(skynet.pack(f(...)))
	end)
end)
