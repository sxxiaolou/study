local skynet = require "skynet"
local status = {}

HUMAN_STATUS_NORMAL             = 1	-- 正常状态
HUMAN_STATUS_COLLECT            = 2	-- 采集状态
HUMAN_STATUS_SIT_ONE            = 3	-- 打坐

HUMAN_STATUS_SIT_DOUBLE = 4			-- 双休
HUMAN_STATUS_FISH = 5 					-- 钓鱼
HUMAN_STATUS_MINING = 6					-- 挖矿
HUMAN_STATUS_GIDDY = 7					-- 僵直
HUMAN_STATUS_ROTATION = 8 			-- 旋风
HUMAN_STATUS_SING = 9					  -- 吟唱
HUMAN_STATUS_GUIDE = 10					-- 引导
HUMAN_STATUS_HIDE = 11					-- 隐身
HUMAN_STATUS_READY = 12					-- 回城读条
HUMAN_STATUS_TALISMAN = 13			-- 上坐骑读条
HUMAN_STATUS_ROTATION1 = 14     -- 小旋风
HUMAN_STATUS_CANGBAO = 15				-- 藏宝读条
HUMAN_STATUS_OBSERVER = 16				-- 擂台观战
HUMAN_STATUS_COPY_ENTER = 17			-- 副本进入读条
HUMAN_STATUS_WING_FLY = 18				-- 飞翔

HUMAN_STATUS_SWAP_SKILL = 20			-- 技能切换中
MAX_HUMAN_STATUS_NUM = 20				-- 最大的状态

function status.send_view_status(obj)
	obj.old_displays = obj.old_displays or {}
	local old_displays = obj.old_displays

	--GC_VIEW_STATUS_CHANGE--start-
	local ret_data = {}
	ret_data.protoid = 740
	ret_data.iid = obj.id
	ret_data.status = HUMAN_STATUS_NORMAL
	skynet.send(obj.agent,"lua","send_client",ret_data)
	--GC_VIEW_STATUS_CHANGE--end-
end

return status