local skynet = require "skynet"
local hksend = require "hksend"
-- local hksend = require "hksend"

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
					local arr_len
					arr_len,start_idx = read_int(msg_data,start_idx,key,len,limit)
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
			elseif key_type == "double" then
				if len > 1 then
					local int_double = {}
					local arr_len,start_idx = read_int(msg_data,start_idx,key,len,limit)
					for i=1,arr_len do
						if i > len then
							print("[:'log']--['file':msgservice.lua]--['fun':PARES_CG]","double_array arr_len > len error")
							break
						end

						local double_value
						double_value,start_idx = read_double(msg_data,start_idx,key,len,limit)
						table.insert(int_double,i,double_value)
					end
					proto_data[key] = int_double
				else
					proto_data[key],start_idx = read_double(msg_data,start_idx,key,len,limit)
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

function read_int(msg_data,start_idx,key,len,limit,is_double)
	local int_len = string.byte(msg_data,start_idx)
	-- print("[:'log']--['file':msgservice.lua]--['fun':read_int]","--['start_idx:']",start_idx,"--['int_len:']",int_len,#msg_data)
	start_idx = start_idx + 1
	local ret_int = 0
	local read_len = 0
	for i=1,int_len do
		-- print("[:'log']-1-['file':msgservice.lua]--['fun':read_int]","--['start_idx:']",start_idx)
		local int_value = string.byte(msg_data,start_idx)
		-- print("[:'log']-2-['file':msgservice.lua]--['fun':read_int]--['char':]",string.char(int_value))
		-- print("[:'log']-3-['file':msgservice.lua]--['fun':read_int]","--['int_value:']",int_value)
		int_value = tonumber(int_value) << (read_len*8)
		-- print("[:'log']-4-['file':msgservice.lua]--['fun':read_int]","--['start_idx:']",start_idx,"--['int_value:']",int_value,#msg_data)
		ret_int =  ret_int + int_value
		read_len =  read_len + 1
		start_idx = start_idx + 1
	end

	if is_double == nil and ret_int > 2147483647 then
		ret_int = ret_int - 4294967296
	end

	-- print("[:'log']--['file':msgservice.lua]--['fun':read_int]","--['start_idx:']",start_idx,"--['ret_int:']",ret_int)
	return ret_int,start_idx
end

function read_double(msg_data,start_idx,key,len,limit)
	local ret_double
	local high_uint
	local low_uint
	high_uint,start_idx = read_int(msg_data,start_idx,key,len,limit,true)
	low_uint,start_idx = read_int(msg_data,start_idx,key,len,limit,true)
	ret_double = ( high_uint << 32 ) + low_uint
	if ret_double > 140737488355327 then
		ret_double = ret_double - 281474976710656
	end
	-- print("[:'log']--['file':msgservice.lua]--['fun':read_double]","--['start_idx:']",start_idx,"--['ret_double:']",ret_double)
	return ret_double,start_idx
end

function CMD.PARES_GC(protoid,lua_data)
	local proto_id_conf = proto_id[protoid]
	local protos = nil
	if proto_id_conf ~= nil then
		protos = proto_by_module[proto_id_conf.module][proto_id_conf.name]
	end
	local str_data = ""
	if protos ~= nil then
		str_data = str_data..write_int(protoid)
		for k,v in pairs(protos) do
			local key = v[1]
			local len = v[2]
			local key_type = v[3]
			local limit = v[4]
			if limit == nil then
				limit = 0
			end
			local str = ""
			print("[:'log']--['file':msgservice.lua]--['fun':PARES_GC]",key,len,key_type,limit)
			--to do 处理limit限制
			if key_type == "string" then
				str_data = str_data..write_string(lua_data,key,len,limit)
			elseif key_type == "int" then
				if len > 1 then
					local int_array = lua_data[key]
					local arr_len = #int_array
					str_data = str_data..write_int(arr_len)
					for i=1,arr_len do
						if i > len then
							print("[:'log']--['file':msgservice.lua]--['fun':PARES_GC]","int_array arr_len > len error")
							break
						end
						str_data = str_data..write_int(int_array[i])
					end
				else
					str_data = str_data..write_int(lua_data[key])
				end
			elseif key_type == "double" then
				if len > 1 then
					local int_double = lua_data[key]
					local arr_len = #int_double
					str_data = str_data..write_int(arr_len)
					for i=1,arr_len do
						if i > len then
							print("[:'log']--['file':msgservice.lua]--['fun':PARES_GC]","double_array arr_len > len error")
							break
						end
						str_data = str_data..write_double(int_double[i])
					end
				else
					str_data = str_data..write_double(lua_data[key])
				end
			else
			end
		end
	end
	return str_data
end

function write_string(lua_data,key,len,limit)
	local str = lua_data[key]
	local str_len = #str
	local ret_str = ""
	ret_str = ret_str..write_int(str_len)
	ret_str = ret_str..str
	return ret_str
end

function write_int(lua_data)
	local ret_str = ""
	local byte_char
	local null_char
	local v_1
	local v_2
	local v_3
	local v_4
	
	byte_char,v_1,v_2,v_3,v_4,null_char = hksend.hkwrite_int(lua_data);
	local int_byte = string.byte(byte_char,1)
	local int_null = string.byte(null_char,1)
	local idx = 0

	-- print("[:'log']--['file':msgservice.lua]--['fun':write_int]",int_byte,v_1,v_2,v_3,v_4,int_null)
	ret_str = ret_str..byte_char

	if idx < int_byte then
		if (int_null & 1) == 1 then
			ret_str = ret_str.."\0"
		else
			ret_str = ret_str..v_1
		end
		idx = idx+1
	end

	if idx < int_byte then
		if (int_null & 2) ==2 then
			ret_str = ret_str.."\0"
		else
			ret_str = ret_str..v_2
		end
		idx = idx+1
	end

	if idx < int_byte then
		if (int_null & 4) == 4 then
			ret_str = ret_str.."\0"
		else
			ret_str = ret_str..v_3
		end
		idx = idx+1
	end

	if idx < int_byte then
		if (int_null & 8) == 8 then
			ret_str = ret_str.."\0"
		else
			ret_str = ret_str..v_4
		end
		idx = idx+1
	end

	return ret_str
end

DOUBLE_MAX = 140737488355327
DOUBLE_MIN = -140737488355328
function write_double(lua_data)
	local ret_str = ""
	if lua_data>DOUBLE_MAX then
		lua_data = DOUBLE_MAX
	elseif lua_data < DOUBLE_MIN then
		lua_data = DOUBLE_MIN
	end

	local high_flag = 0x7fff
	if lua_data < 0 then
		lua_data = 281474976710655 + lua_data + 1
		high_flag = high_flag | 0x8000
	end
	local low_uint = lua_data & 0xffffffff
	local high_uint = lua_data >> 32
	ret_str = ret_str..write_int(high_uint)
	ret_str = ret_str..write_int(low_uint)
	return ret_str
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
