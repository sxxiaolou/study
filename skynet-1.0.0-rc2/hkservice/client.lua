package.cpath = "luaclib/?.so"
package.path = "lualib/?.lua;hkservice/?.lua"

if _VERSION ~= "Lua 5.3" then
	error "Use lua 5.3"
end

local socket = require "clientsocket"

-- local fd = assert(socket.connect("127.0.0.1", 8888))
local fd = assert(socket.connect("172.22.28.2", 2016))

local session = 0

local function send_package(fd, pack)
	session = session + 1
	print("[:'log']--['file':client.lua]--['fun':send_package]--['pack:']",pack)
	local package = string.pack(">s2", pack)
	socket.send(fd, package)
	print("[:'log']--['file':client.lua]--['fun':send_package]--['package:']",package)
	print("send_package:", session)
end

local function unpack_package(text)
	local size = #text
	if size < 2 then
		return nil, text
	end
	local s = text:byte(1) + text:byte(2)

	return s, text:sub(3,s+3)
end

local function recv_package(last)
	local r = socket.recv(fd)
	if not r then
		return nil, last
	end
	if r == "" then
		error "Server closed"
	end
	-- print("[:'log']--['file':client.lua]--['fun':unpack_package]--['r:']",r)
	return unpack_package(r)
end

local last = ""

local function print_package(len, str)
	print(len,str)
end

local function dispatch_package()
	while true do
		local v
		v, last = recv_package(last)
		if not v then
			break
		end

		print_package(v,last)
	end
end

while true do
	dispatch_package()
	local cmd = socket.readstdin()
	if cmd then
		send_package(fd,cmd)
	else
		socket.usleep(100)
	end
end
