local skynet = require "skynet"

local CMD = {}
skynet.start(function()
	skynet.dispatch("lua", function(session, source, cmd, ...)
		print("[:'log']--['file':dbservice.lua]--['fun':lua dispatch]",session,source,cmd,protoid,...)
		local f = assert(CMD[cmd])
		skynet.ret(skynet.pack(f(...)))
	end)
	init_dbservice()
end)

function init_dbservice()
	print("[:'log']--['file':msgservice.lua]--['fun':init_dbservice]")
end