local skynet = require "skynet"
local MapConf = require "confs.Map"
local MapEx = require "core.MapEx"


local CMD = {}
local all_scene = {}                                                              --所有场景
local timer_service                                                               --时间服务

skynet.start(function()
	skynet.dispatch("lua", function(session, source, cmd, protoid, ...)
		print("[:'log']--['file':worldservice.lua]--['fun':lua dispatch]",session,source,cmd,protoid,...)
		local f = assert(CMD[cmd])
		local ret_data = f(protoid, ...)
		if ret_data ~= nil then
			skynet.ret(skynet.pack(ret_data))
		end
	end)
	init_allscene()
end)

function init_allscene()
	for scene_id,scene_conf in pairs(MapConf.scene) do
		all_scene[scene_id] = {}
		all_scene[scene_id].scene_conf = scene_conf
		all_scene[scene_id].mapex_conf = MapEx[scene_id]
		all_scene[scene_id].scene_service_id = skynet.newservice("sceneservice")
		skynet.send(all_scene[scene_id].scene_service_id,"lua","initscene",scene_id,all_scene[scene_id])
	end
end

function CMD.enterworld(human)
	local scene = all_scene[human.db_data.scene_id]
	skynet.send(scene.scene_service_id,"lua","enterscene",human)
end
