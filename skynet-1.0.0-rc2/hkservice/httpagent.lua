local skynet = require "skynet"
local socket = require "socket"
local httpd = require "http.httpd"
local sockethelper = require "http.sockethelper"
local urllib = require "http.url"
local table = table
local string = string
local json = require "json"

local sharedata = require "sharedata"


skynet.start(function()
	skynet.dispatch("lua", function(session, source, id, ...)
		print("[:'log']--['file':httpagent.lua]--['fun':lua dispatch]",session,source,id,...)
		socket.start(id)
		-- limit request body size to 8192 (you can pass nil to unlimit)
		local code, url, method, header, body = httpd.read_request(sockethelper.readfunc(id), 8192)
		print("url:",url)
		if code then
			if code ~= 200 then
				response(id, code)
			else
				local package
				local str
				local cmd = string.sub(url,2)
				if(cmd == "map") then
					str = get_map_conf()
				end
				
				local package = string.pack(">s2", str)
				response(id, code,package)
			end
		else
			if url == sockethelper.socket_error then
				skynet.error("socket closed")
			else
				skynet.error(url)
			end
		end
		socket.close(id)
	end)
end)

local map_conf = nil
function get_map_conf()
	if map_conf == nil then
		map_conf = {}
		local MapConf = sharedata.query("MapConf")
		local MapEx = sharedata.query("MapEx")
		map_conf.scene = MapConf.scene
	end
	return json.encode(map_conf)
end


function response(id, ...)
	local ok, err = httpd.write_response(sockethelper.writefunc(id), ...)
	if not ok then
		-- if err == sockethelper.socket_error , that means socket closed.
		skynet.error(string.format("fd = %d, %s", id, err))
	end
end
