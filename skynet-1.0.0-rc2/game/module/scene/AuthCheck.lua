local Config = require "common.Config"
local authCheck = {}

function authCheck.AuthCheck(account,authkey)
	if Config.CHECK_AUTH == false then
		return true
	end


end

return authCheck