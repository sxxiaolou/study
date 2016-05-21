local roleConfig = {}

function roleConfig.get_default_db()
	local db={
		-- _id = "",
		account = "",
		name = "",
		lvl = 1,
		ip = "",
		cid = 0,
	}
	return db
end

return roleConfig