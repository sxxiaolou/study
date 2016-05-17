local skynet = require "skynet.manager"


local max_client = 64

skynet.start(function()
	print("Server start")
	local console = skynet.newservice("console")
	skynet.newservice("debug_console",8000)
	skynet.newservice("simpledb")
	local watchdog = skynet.newservice("watchdog")
	skynet.call(watchdog, "lua", "start", {
		port = 2016,
		address="172.22.28.2",
		maxclient = max_client,
		nodelay = true,
	})
	print("Watchdog listen on ", 8888)
	local msgservice = skynet.newservice("msgservice")
	skynet.name(".msgservice", msgservice)

	skynet.exit()
end)
