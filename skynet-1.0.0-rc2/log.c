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
LAUNCH snlua bootstrap[:'log']--['file':skynet_start.c]--['fun':start]--['id':3]--[128/4]

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
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	6	8	start	table: 0x7fe303c2a820
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	3	12	open	table: 0x7fe303c23ae0
[:0000000d] Listen on 172.22.28.2:2016
Watchdog listen on 	8888
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	nil
[:0000000e] LAUNCH snlua msgservice
[:'log']--['file':msgservice.lua]--['fun':init_msgservice]
[:00000008] KILL self
[:00000002] KILL self
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	open	4	172.22.28.1:37634
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	0	13	socket	open	4	172.22.28.1:37634
[:0000000c] New client from : 172.22.28.1:37634
[:0000000f] LAUNCH snlua agent
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	2	15	forward	4
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	nil
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	userdata: 0x7fe304021428	nil
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	userdata: 0x7fe304021428	data	4	userdata: 0x7fe303c38b20	83
[:'log']--['file':agent.lua]--['fun':client dispatch]--['res_msg:']	hankaihankaihankaihankai ���   ���������� � N��� ������	--['size:']	83	--['len:']	83
[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid_high:']	4	--['protoid_low']	5
[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid:']	1029	81
[:'log']--['file':agent.lua]--['fun':client dispatch]--['handler_id:']	14
[:'log']--['file':msgservice.lua]--['fun':lua dispatch]	3	15	PARES_CG	1029	hankaihankaihankaihankai ���   ���������� � N��� ������
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
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	testdouble	5	double	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	50	--['ret_int:']	5
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	53	--['ret_int:']	32767
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	58	--['ret_int:']	4294967295
[:'log']--['file':msgservice.lua]--['fun':read_double]	--['start_idx:']	58	--['ret_double:']	140737488355327
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	61	--['ret_int:']	32768
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	63	--['ret_int:']	0
[:'log']--['file':msgservice.lua]--['fun':read_double]	--['start_idx:']	63	--['ret_double:']	-140737488355328
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	65	--['ret_int:']	12
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	70	--['ret_int:']	3348277326
[:'log']--['file':msgservice.lua]--['fun':read_double]	--['start_idx:']	70	--['ret_double:']	54887884878
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	72	--['ret_int:']	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	74	--['ret_int:']	1
[:'log']--['file':msgservice.lua]--['fun':read_double]	--['start_idx:']	74	--['ret_double:']	1
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	77	--['ret_int:']	65535
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	82	--['ret_int:']	4294967295
[:'log']--['file':msgservice.lua]--['fun':read_double]	--['start_idx:']	82	--['ret_double:']	-1
[:'log']--['file':msgservice.lua]--['fun':lua dispatch]	4	15	PARES_GC	590	table: 0x7fe303c39700
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	account	1	string	0
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	obj_id	1	int	0
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	x	1	int	0
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	y	1	int	0
[:'log']--['file':msgservice.lua]--['fun':PARES_GC]	points	128	int	0
[:'log']--['file':agent.lua]--['fun':send_client]	50
