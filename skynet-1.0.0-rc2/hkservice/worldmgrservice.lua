local skynet = require "skynet"
local CMD = {}
local allworld = {}

skynet.start(function()
	skynet.dispatch("lua", function(session, source, cmd, protoid, ...)
		print("[:'log']--['file':worldmgrservice.lua]--['fun':lua dispatch]",session,source,cmd,protoid,...)
		local f = assert(CMD[cmd])
		local ret_data = skynet.pack(f(protoid, ...))
		if ret ~= nil then
			skynet.ret(ret_data)
		end
	end)
	init_worldservice()
end)

function init_worldservice()
	--这里可以做分线功能
	allworld[1] = skynet.newservice("worldservice")
end