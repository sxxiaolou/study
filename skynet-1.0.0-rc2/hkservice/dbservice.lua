local skynet = require "skynet"
local mongo = require "mongo"
local bson = require "bson"

local Config = require "common.Config"
local RoleConfig = require "common.RoleConfig"
local db

local db_counts = "counts"				 --自增计数表
local db_char = "char"                                                  --角色表

QueryByAccount = {}

local CMD = {}

function CMD.loadRole(lua_data)
	QueryByAccount.account = lua_data.account
	local data = db[Config.DB_NAME].char:find(QueryByAccount)
	-- print("[:'log']--['file':dbservice.lua]--['fun':loadRole]","data:",data)
	if data:hasNext() then
		data = data:next()
	else
		data = nil
	end


	--新用户则创建数据
	if data == nil then
		data = RoleConfig.get_default_db()
		data.account = lua_data.account
		data._id = nil
		--cid自增
		local cid_data = db[Config.DB_NAME].counts:findAndModify({query = {name = "cid"}, update = {["$inc"] = {id = 1}},})
		data.cid = cid_data.value.id
		local ret = db[Config.DB_NAME].char:insert(data)
		print("[:'log']--['file':dbservice.lua]--['fun':loadRole]","new role data._id:",data._id)
	end
	-- db[Config.DB_NAME].char:update({_id=data._id},data)
	return data
end

skynet.start(function()
	skynet.dispatch("lua", function(session, source, cmd, ...)
		print("[:'log']--['file':dbservice.lua]--['fun':lua dispatch]",session,source,cmd,protoid,...)
		local f = assert(CMD[cmd])
		skynet.ret(skynet.pack(f(...)))
	end)
	init_dbservice()
end)

function init_dbservice()
	print("[:'log']--['file':dbservice.lua]--['fun':init_dbservice]")
	db = mongo.client({host = Config.DB_IP})
	db[Config.DB_NAME].char:ensureIndex({name = 1},{unique = true})
	db[Config.DB_NAME].char:ensureIndex({account = 1},{unique = true})
end