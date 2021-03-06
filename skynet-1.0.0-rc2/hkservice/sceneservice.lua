local skynet = require "skynet"
local scene_handler = require "module.scene.Handler"
local obj_conf = require "common.ObjConfig"

local CMD = {}
local _scene_id
local _conf
local _bin_map
local _w                                                                               ---场景宽
local _h                                                                                ---场景高
local _list_monster = {}                                                        ---怪物
local _list_add_obj = nil                                                       ---其他显示对象
local _iid = 0
local _all_objs = {}                                                                ---场景中所有显示对象

function _file2str(filename)
	local f = io.open(filename,"rb")
	if not f then
		assert(nil,filename)
	end
	local str = f:read("*a")
	assert(io.close(f))
	return str
end

skynet.start(function()
	skynet.dispatch("lua", function(session, source, cmd, protoid, ...)
		print("[:'log']--['file':scene.lua]--['fun':lua dispatch]",session,source,cmd,protoid,...)
		local f = assert(CMD[cmd])
		local ret_data = f(protoid, ...)
		if ret_data ~= nil then
			skynet.ret(skynet.pack(ret_data))
		end
	end)
end)

function CMD.initscene(scene_id,conf)
	_scene_id = scene_id
	_conf = conf
	_iid = 10000 --默认10000之前是玩家
	print("[:'log']--['file':scene.lua]--['fun':lua initscene]",_conf.scene_conf.name)
	local str = _file2str("map/".._conf.scene_conf.map_id..".map")
	_w = math.ceil(_conf.mapex_conf.rect[-1][1][3]/25)
	_h = math.ceil(_conf.mapex_conf.rect[-1][1][4]/25)
	_bin_map = string.sub(str,9,8+_w*_h)
	print("[:'log']--['file':scene.lua]--['fun':lua initscene]","_w:",_w,"    _h:",_h)
	if _conf.mapex_conf.monster then
		for group, v in pairs(_conf.mapex_conf.monster) do
			for _, vv in ipairs(v) do
				local id,x,y = vv[1],vv[2],vv[3]
				_list_monster[group] = _list_monster[group] or {}
				_list_monster[group][x] = _list_monster[group][x] or {}
				if _list_monster[group][x][y] then
					assert()
				end
				_list_monster[group][x][y] = id
				-- print("[:'log']--['file':scene.lua]--['fun':lua initscene]","id:",id,"    x:",x,"     y:",y)
			end
		end
	end

	if not _list_add_obj then
	end
end

function CMD.enterscene(human)
	print("[:'log']--['file':scene.lua]--['fun':lua enterscene]",human.db_data.account)
	human.obj_type = obj_conf.TYPE_HUMAN --玩家
	_all_objs[human.id] = human

	--GC_ENTER_SCENE--start-
	local ret_data = {}
	ret_data.protoid = 430
	ret_data.scene_id = _scene_id
	ret_data.x = human.db_data.x
	ret_data.y = human.db_data.y
	ret_data.mapType = _conf.scene_conf.mapType
	ret_data.iid = human.id
	skynet.send(human.agent,"lua","send_client",ret_data)
	--GC_ENTER_SCENE--end-

	scene_handler.user_login(human)
end