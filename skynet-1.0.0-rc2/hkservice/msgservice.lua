local skynet = require "skynet"

--优化 协议解析可以放到c中

proto_id = proto_id or {}
proto_name = proto_name or {}
proto_by_module = proto_by_module or {}

local CMD = {}
--解析客户端协议
function CMD.PARES_CG(protoid,msg_data)
	local proto_id_conf = proto_id[protoid]
	local protos = nil
	if proto_id_conf ~= nil then
		protos = proto_by_module[proto_id_conf.module][proto_id_conf.name]
	end
	local proto_data = nil
	if protos ~= nil then
		proto_data = {}
		proto_data.service = proto_id_conf.service
		proto_data.service_fun = proto_id_conf.name
		local start_idx = 1
		for k,v in pairs(protos) do
			local key = v[1]
			local len = v[2]
			local key_type = v[3]
			local limit = v[4]
			if limit == nil then
				limit = 0
			end
			print("[:'log']--['file':msgservice.lua]--['fun':PARES_CG]",key,len,key_type,limit)
			--to do 处理limit限制
			if key_type == "string" then
				proto_data[key],start_idx = read_string(msg_data,start_idx,key,len,limit)
			elseif key_type == "int" then
				if len > 1 then
					local int_array = {}
					local arr_len,start_idx = read_int(msg_data,start_idx,key,len,limit)
					for i=1,arr_len do
						if i > len then
							print("[:'log']--['file':msgservice.lua]--['fun':PARES_CG]","int_array arr_len > len error")
							break
						end

						local int_value
						int_value,start_idx = read_int(msg_data,start_idx,key,len,limit)
						table.insert(int_array,i,int_value)
					end
					proto_data[key] = int_array
				else
					proto_data[key],start_idx = read_int(msg_data,start_idx,key,len,limit)
				end
			else
			end
		end
	end
	return proto_data
end

function read_string(msg_data,start_idx,key,len,limit)
	local len,start_idx = read_int(msg_data,start_idx,nil,nil,nil)
	-- print("[:'log']--['file':msgservice.lua]--['fun':read_string]","--['start_idx:']",start_idx,"--['len:']",len)
	local ret_string = string.sub(msg_data,start_idx,start_idx+len-1)
	start_idx = start_idx + len
	print("[:'log']--['file':msgservice.lua]--['fun':read_string]","--['start_idx:']",start_idx,"--['ret_string:']",ret_string)
	return ret_string,start_idx
end

function read_int(msg_data,start_idx,key,len,limit)
	local int_len = string.byte(msg_data,start_idx)
	-- print("[:'log']--['file':msgservice.lua]--['fun':read_int]","--['start_idx:']",start_idx,"--['int_len:']",int_len,#msg_data)
	start_idx = start_idx + 1
	local ret_int = 0
	local read_len = 0
	for i=1,int_len do
		-- print("[:'log']--['file':msgservice.lua]--['fun':read_int]","--['start_idx:']",start_idx)
		local int_value = string.byte(msg_data,start_idx)
		-- print("[:'log']--['file':msgservice.lua]--['fun':read_int]","--['int_value:']",int_value)
		int_value = tonumber(int_value) << (read_len*8)
		-- print("[:'log']--['file':msgservice.lua]--['fun':read_int]","--['start_idx:']",start_idx,"--['int_value:']",int_value,#msg_data)
		ret_int =  ret_int + int_value
		read_len =  read_len + 1
		start_idx = start_idx + 1
	end
	print("[:'log']--['file':msgservice.lua]--['fun':read_int]","--['start_idx:']",start_idx,"--['ret_int:']",ret_int)
	return ret_int,start_idx
end

function CMD.PARES_GC(protoid,lua_data)
	local proto_id_conf = proto_id[protoid]
	local protos = nil
	if proto_id_conf ~= nil then
		protos = proto_by_module[proto_id_conf.module][proto_id_conf.name]
	end
	local proto_data = nil
end

skynet.start(function()
	skynet.dispatch("lua", function(session, source, cmd, protoid, ...)
		print("[:'log']--['file':msgservice.lua]--['fun':lua dispatch]",session,source,cmd,protoid,...)
		local f = assert(CMD[cmd])
		skynet.ret(skynet.pack(f(protoid, ...)))
	end)
	init_msgservice()
end)

function init_msgservice()
	print("[:'log']--['file':msgservice.lua]--['fun':init_msgservice]")
	local proto_id_conf = require("common.protoid")
	if proto_id_conf ~= nil then
		for k,v in pairs(proto_id_conf) do
			if type(k) == "number" then
				-- print("[:'log']--['file':msgservice.lua]--['fun':init_msgservice]","--['k']",k,"--['name:']",v.name)
				proto_id[k] = v
				proto_name[v.name] = v
				local protos = require("module."..v.module..".Proto")
				proto_by_module[v.module] = protos
			end
		end
	end
end
