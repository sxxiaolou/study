local skynet = require "skynet"
local CMD = {}
local _allWorld = {}
local _allWorldCid2ClientFd = {}

skynet.start(function()
	skynet.dispatch("lua", function(session, source, cmd, protoid, ...)
		print("[:'log']--['file':worldmgrservice.lua]--['fun':lua dispatch]",session,source,cmd,protoid,...)
		local f = assert(CMD[cmd])
		local ret_data = f(protoid, ...)
		if ret_data ~= nil then
			skynet.ret(skynet.pack(ret_data))
		end
	end)
	init_worldservice()
end)

function init_worldservice()
	--这里可以做分线功能
	_allWorld[1] = skynet.newservice("worldservice")
end

function CMD.enterworld(human)
	_allWorldCid2ClientFd[human.db_data.cid] = human.db_data.client_fd
	skynet.send(_allWorld[1],"lua","enterworld",human)
end