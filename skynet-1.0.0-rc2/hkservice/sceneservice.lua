local skynet = require "skynet"

local CMD = {}
local _conf

skynet.start(function()
	skynet.dispatch("lua", function(session, source, cmd, protoid, ...)
		print("[:'log']--['file':scene.lua]--['fun':lua dispatch]",session,source,cmd,protoid,...)
		local f = assert(CMD[cmd])
		local ret_data = skynet.pack(f(protoid, ...))
		if ret ~= nil then
			skynet.ret(ret_data)
		end
	end)
end)

function CMD.initscene(conf)
	_conf = conf
	print("[:'log']--['file':scene.lua]--['fun':lua initscene]",_conf.scene_conf.name)
end