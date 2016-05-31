local obj_conf = require "common.ObjConfig"
local obj_human = require "core.ObjHuman"
local obj = {}

function obj.get_body_info(obj_instance)
	if(obj_instance.obj_type == obj_conf.TYPE_HUMAN) then
		return obj_human.get_body_info(obj_instance)
	end
end

return obj