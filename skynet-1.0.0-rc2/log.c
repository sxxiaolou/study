[:'log']--['file':skynet_start.c]--['fun':skynet_start]--[]
[:log]--[file:skynet_harbor.c]--[fun:skynet_harbor_init]--[harbor:0]--[HARBOR:4294967295]
[:log]--[file:skynet_harbor.c]--[fun:skynet_harbor_init]--[harbor:0]--[HARBOR:0]
[:log]--[file:skynet_module.c]--[fun:skynet_module_init]--[path:./cservice/?.so]
[:log]--[file:service_logger.c]--[fun:logger_init]--[parm:(null)]
[:'log']--['file':skynet_start.c]--['fun':start]--['id':0]--[128/4]
[:'log']--['file':skynet_start.c]--['fun':start]--['weight':-1]
[:'log']--['file':skynet_start.c]--['fun':start]--['id':1]--[128/4]
[:'log']--['file':skynet_start.c]--['fun':start]--['weight':-1]
[:00000001] LAUNCH logger 
[:'log']--['file':skynet_start.c]--['fun':start]--['id':2]--[128/4]
[:00000002] [:'log']--['file':skynet_start.c]--['fun':start]--['weight':-1]
LAUNCH snlua bootstrap
[:'log']--['file':skynet_start.c]--['fun':start]--['id':3]--[128/4]
[:'log']--['file':skynet_start.c]--['fun':start]--['weight':-1]
[:'log']--['file':skynet_start.c]--['fun':start]--['id':4]--[128/4]
[:'log']--['file':skynet_start.c]--['fun':start]--['weight':0]
[:'log']--['file':skynet_start.c]--['fun':start]--['id':5]--[128/4]
[:'log']--['file':skynet_start.c]--['fun':start]--['weight':0]
[:'log']--['file':skynet_start.c]--['fun':start]--['id':6]--[128/4]
[:'log']--['file':skynet_start.c]--['fun':start]--['weight':0]
[:'log']--['file':skynet_start.c]--['fun':start]--['id':7]--[128/4]
[:'log']--['file':skynet_start.c]--['fun':start]--['weight':0]
[:00000003] LAUNCH snlua launcher
[:00000004] LAUNCH snlua cdummy
[:00000005] LAUNCH harbor 0 4
[:00000006] LAUNCH snlua datacenterd
[:00000007] LAUNCH snlua service_mgr
[:00000008] LAUNCH snlua main
Server start
[:00000009] LAUNCH snlua console
[:0000000a] LAUNCH snlua debug_console 8000
[:0000000a] Start debug console at 127.0.0.1 8000
[:0000000b] LAUNCH snlua simpledb
[:0000000c] LAUNCH snlua watchdog
[:0000000d] LAUNCH snlua gate
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	6	8	start	table: 0x7ffd50d12410
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	3	12	open	table: 0x7ffd50d0b6d0
[:0000000d] Listen on 172.22.28.2:2016
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	nil
Watchdog listen on 	8888
[:0000000e] LAUNCH snlua msgservice
[:'log']--['file':msgservice.lua]--['fun':init_msgservice]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':2147483648]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':0]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':0]--['int_byte':2]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':0]--['int_byte':3]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':128]--['int_byte':4]
   �
[:00000008] KILL self
[:00000002] KILL self
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	open	4	172.22.28.1:47661
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	0	13	socket	open	4	172.22.28.1:47661
[:0000000c] New client from : 172.22.28.1:47661
[:0000000f] LAUNCH snlua agent
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	2	15	forward	4
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	nil
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	data	4	userdata: 0x7ffd50d12370	49
[:'log']--['file':agent.lua]--['fun':client dispatch]--['res_msg:']	hankaihankaihankaihankai ���   �����	--['size:']	49	--['len:']	49
[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid_high:']	4	--['protoid_low']	5
[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid:']	1029	47
[:'log']--['file':agent.lua]--['fun':client dispatch]--['handler_id:']	14
[:'log']--['file':msgservice.lua]--['fun':lua dispatch]	3	15	PARES_CG	1029	hankaihankaihankaihankai ���   �����
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	account	1	string	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	3	--['ret_int:']	12
[:'log']--['file':msgservice.lua]--['fun':read_string]	--['start_idx:']	15	--['ret_string:']	hankaihankai
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	authkey	1	string	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	17	--['ret_int:']	12
[:'log']--['file':msgservice.lua]--['fun':read_string]	--['start_idx:']	29	--['ret_string:']	hankaihankai
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	testint	4	int	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	31	--['ret_int:']	4
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	33	--['ret_int:']	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	38	--['ret_int:']	2147483647
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	43	--['ret_int:']	-2147483648
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	48	--['ret_int:']	-1
[:'log']--['file':msgservice.lua]--['fun':lua dispatch]	4	15	PARES_GC	590	table: 0x7ffd50d00c50
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':590]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':78]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':2]--['int_byte':2]
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	account	1	string	0
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':6]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':6]--['int_byte':1]
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	obj_id	1	int	0
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':0]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':0]--['int_byte':1]
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	x	1	int	0
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':4294967295]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':255]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':255]--['int_byte':2]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':255]--['int_byte':3]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':255]--['int_byte':4]
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	y	1	int	0
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':2147483648]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':0]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':0]--['int_byte':2]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':0]--['int_byte':3]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':128]--['int_byte':4]
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	points	128	int	0
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':6]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':6]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':10000]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':16]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':39]--['int_byte':2]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':888888]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':56]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':144]--['int_byte':2]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':13]--['int_byte':3]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':99999]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':159]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':134]--['int_byte':2]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':1]--['int_byte':3]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':1000000]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':64]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':66]--['int_byte':2]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':15]--['int_byte':3]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':777777777]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':113]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':242]--['int_byte':2]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':91]--['int_byte':3]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':46]--['int_byte':4]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':2147483647]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':255]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':255]--['int_byte':2]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':255]--['int_byte':3]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':127]--['int_byte':4]
[:'log']--['file':agent.lua]--['fun':send_client]	50
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	error	4	Connection reset by peer
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	0	13	socket	error	4	Connection reset by peer
socket error	4	Connection reset by peer
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	6	12	kick	4
[:0000000f] KILL self
