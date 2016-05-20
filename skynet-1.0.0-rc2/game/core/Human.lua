has_load = has_load or false

if has_load then
	return human
end

local human = {}

human.onlineHumen = onlineHumen
human.onlineAccout = onlineAccout
human.onlineUuid = onlineUuid

--人物的队列id
human.id = 1

return human
