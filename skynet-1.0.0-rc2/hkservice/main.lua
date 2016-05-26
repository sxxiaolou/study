local skynet = require "skynet.manager"


local max_client = 5000

skynet.start(function()
	print("Server start")
	local console = skynet.newservice("console")
	skynet.newservice("debug_console",8000)

	local dbservice = skynet.newservice("dbservice")
	skynet.name(".dbservice", dbservice)

	local watchdog = skynet.newservice("watchdog")
	skynet.name(".watchdog", watchdog)

	local msgservice = skynet.newservice("msgservice")
	skynet.name(".msgservice", msgservice)

	local worldmgrservice = skynet.newservice("worldmgrservice")
	skynet.name(".worldmgrservice", worldmgrservice)
	
	skynet.call(watchdog, "lua", "start", {
		port = 2016,
		address="172.22.28.2",
		maxclient = max_client,
		nodelay = true,
		worldmgrservice = worldmgrservice,
	})

	local httpservice = skynet.newservice("httpservice")
	
	print("Watchdog listen on ", 2016)
	
	skynet.exit()
end)
