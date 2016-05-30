local skynet = require "skynet"
local status = require "module.scene.Status"
local handler = {}

function handler.user_login(human)

	--状态信息
	status.send_view_status(human)
end

return handler