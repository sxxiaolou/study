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
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	6	8	start	table: 0x7fb02c925c00
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	3	12	open	table: 0x7fb02c925bc0
[:0000000d] Listen on 172.22.28.2:2016
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	nil
Watchdog listen on 	8888
[:0000000e] LAUNCH snlua msgservice
[:'log']--['file':msgservice.lua]--['fun':init_msgservice]
[:00000008] KILL self
[:00000002] KILL self
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	open	4	172.22.28.1:44595
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	0	13	socket	open	4	172.22.28.1:44595
[:0000000c] New client from : 172.22.28.1:44595
[:0000000f] LAUNCH snlua agent
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	2	15	forward	4
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	nil
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	data	4	userdata: 0x7fb02a70fe40	49
[:'log']--['file':agent.lua]--['fun':client dispatch]--['res_msg:']	hankaihankaihankaihankai ���   �����	--['size:']	49	--['len:']	49
[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid_high:']	4	--['protoid_low']	5
[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid:']	1029	47
[:'log']--['file':agent.lua]--['fun':client dispatch]--['handler_id:']	14
[:'log']--['file':msgservice.lua]--['fun':lua dispatch]	4	15	PARES_CG	1029	hankaihankaihankaihankai ���   �����
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	account	1	string	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	1	--['int_len:']	1	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	2

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	12
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	2	--['int_value:']	12	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	3	--['ret_int:']	12
[:'log']--['file':msgservice.lua]--['fun':read_string]	--['start_idx:']	15	--['ret_string:']	hankaihankai
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	authkey	1	string	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	15	--['int_len:']	1	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	16

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	12
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	16	--['int_value:']	12	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	17	--['ret_int:']	12
[:'log']--['file':msgservice.lua]--['fun':read_string]	--['start_idx:']	29	--['ret_string:']	hankaihankai
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	testint	4	int	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	29	--['int_len:']	1	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	30

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	4
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	30	--['int_value:']	4	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	31	--['ret_int:']	4
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	31	--['int_len:']	1	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	32
 
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	32	--['int_value:']	0	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	33	--['ret_int:']	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	33	--['int_len:']	4	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	34
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	34	--['int_value:']	255	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	35
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	35	--['int_value:']	65280	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	36
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	36	--['int_value:']	16711680	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	37

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	127
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	37	--['int_value:']	2130706432	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	38	--['ret_int:']	2147483647
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	38	--['int_len:']	4	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	39
 
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	39	--['int_value:']	0	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	40
 
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	40	--['int_value:']	0	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	41
 
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	41	--['int_value:']	0	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	42
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	128
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	42	--['int_value:']	2147483648	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	43	--['ret_int:']	-2147483648
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	43	--['int_len:']	4	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	44
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	44	--['int_value:']	255	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	45
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	45	--['int_value:']	65280	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	46
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	46	--['int_value:']	16711680	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	47
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	47	--['int_value:']	4278190080	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	48	--['ret_int:']	-1
[:'log']--['file':msgservice.lua]--['fun':lua dispatch]	5	15	PARES_GC	590	table: 0x7fb02a70fea0
[:'log']--['file':lua_hksend.c]--['fun':_hksend_start]
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	account	1	string	0
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['int_value':6]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_int]--['v':6]--['int_byte':1]
[:'log']--['file':lua_hksend.c]--['fun':_hkwrite_string]--['str_value':skynet]--['str_len':6]
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
[:'log']--['file':lua_hksend.c]--['fun':_hksend_end]--['write_start':47]
skynet$����$$$�'8���@Bq�[.���
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	account	1	string	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	1	--['int_len:']	1	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	2

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	6
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	2	--['int_value:']	6	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	3	--['ret_int:']	6
[:'log']--['file':msgservice.lua]--['fun':read_string]	--['start_idx:']	9	--['ret_string:']	skynet
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	obj_id	1	int	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	9	--['int_len:']	1	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	10
$
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	36
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	10	--['int_value:']	36	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	11	--['ret_int:']	36
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	x	1	int	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	11	--['int_len:']	4	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	12
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	12	--['int_value:']	255	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	13
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	13	--['int_value:']	65280	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	14
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	14	--['int_value:']	16711680	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	15
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	15	--['int_value:']	4278190080	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	16	--['ret_int:']	-1
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	y	1	int	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	16	--['int_len:']	4	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	17
$
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	36
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	17	--['int_value:']	36	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	18
$
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	36
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	18	--['int_value:']	9216	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	19
$
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	36
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	19	--['int_value:']	2359296	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	20
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	128
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	20	--['int_value:']	2147483648	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	21	--['ret_int:']	-2145115100
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	points	128	int	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	21	--['int_len:']	1	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	22

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	6
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	22	--['int_value:']	6	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	23	--['ret_int:']	6
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	23	--['int_len:']	2	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	24

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	16
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	24	--['int_value:']	16	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	25
'
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	39
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	25	--['int_value:']	9984	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	26	--['ret_int:']	10000
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	26	--['int_len:']	3	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	27
8
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	56
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	27	--['int_value:']	56	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	28
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	144
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	28	--['int_value:']	36864	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	29

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	13
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	29	--['int_value:']	851968	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	30	--['ret_int:']	888888
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	30	--['int_len:']	3	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	31
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	159
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	31	--['int_value:']	159	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	32
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	134
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	32	--['int_value:']	34304	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	33

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	1
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	33	--['int_value:']	65536	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	34	--['ret_int:']	99999
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	34	--['int_len:']	3	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	35
@
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	64
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	35	--['int_value:']	64	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	36
B
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	66
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	36	--['int_value:']	16896	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	37

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	15
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	37	--['int_value:']	983040	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	38	--['ret_int:']	1000000
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	38	--['int_len:']	4	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	39
q
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	113
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	39	--['int_value:']	113	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	40
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	242
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	40	--['int_value:']	61952	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	41
[
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	91
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	41	--['int_value:']	5963776	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	42
.
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	46
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	42	--['int_value:']	771751936	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	43	--['ret_int:']	777777777
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	43	--['int_len:']	4	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	44
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	44	--['int_value:']	255	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	45
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	45	--['int_value:']	65280	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	46
�
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	255
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	46	--['int_value:']	16711680	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	47

[:'log']--['file':msgservice.lua]--['fun':read_int]	--['int_value:']	127
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	47	--['int_value:']	2130706432	47
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	48	--['ret_int:']	2147483647
[:'log']--['file':agent.lua]--['fun':send_client]	47
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	error	4	Connection reset by peer
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	0	13	socket	error	4	Connection reset by peer
socket error	4	Connection reset by peer
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	6	12	kick	4
[:0000000f] KILL self
