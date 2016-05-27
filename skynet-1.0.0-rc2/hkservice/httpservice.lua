local skynet = require "skynet"
local socket = require "socket"
local httpd = require "http.httpd"
local sockethelper = require "http.sockethelper"
local urllib = require "http.url"
local table = table
local string = string

skynet.start(function()
	local agent = {}
	for i= 1, 1 do
		agent[i] = skynet.newservice("httpagent")
	end
	local balance = 1
	local id = socket.listen("172.22.28.2", 2017)
	skynet.error("Listen web port 2017")
	socket.start(id , function(id, addr)
		skynet.error(string.format("%s connected, pass it to agent :%08x", addr, agent[balance]))
		skynet.send(agent[balance], "lua", id)
		balance = balance + 1
		if balance > #agent then
			balance = 1
		end
	end)
end)