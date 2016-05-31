local obj_human = {}

--形象
function obj_human.get_body_info(human)
	local body = 22
	local bone = 2 --骨骼
	local head = 0

	return {
		body=body,
		bone=bone
	}
end

return obj_human