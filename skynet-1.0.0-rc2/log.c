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
[:'log']--['file':skynet_start.c]--['fun':start]--['weight':-1]
[:00000002] LAUNCH snlua bootstrap
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
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	6	8	start	table: 0x7f897b6262c0
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	3	12	open	table: 0x7f897b626280
[:0000000d] Listen on 172.22.28.2:2016
Watchdog listen on 	8888
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	nil
[:0000000e] LAUNCH snlua msgservice
[:'log']--['file':msgservice.lua]--['fun':init_msgservice]
[:00000008] KILL self
[:00000002] KILL self
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	open	4	172.22.28.1:16331
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	0	13	socket	open	4	172.22.28.1:16331
[:0000000c] New client from : 172.22.28.1:16331
[:0000000f] LAUNCH snlua agent
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	2	15	forward	4
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	nil	nil
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	userdata: 0x7f897d000028	nil
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	userdata: 0x7f897d000028	nil
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	userdata: 0x7f897d000028	nil
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	userdata: 0x7f897d000028	data	4	userdata: 0x7f897b700020	539
[:'log']--['file':agent.lua]--['fun':client dispatch]--['res_msg:']	�对比以往各种迷茫、困惑、无聊的时刻，也才真正明白，其实打败我们的根本不是口中的忙累，而是没有目标的空虚，方法不适的疲惫，以及自我放纵的不坚持。人要成长，首先要做的就是找到自己的方向和目标，寻得正确的方式方法，并为之持续坚持下去，这样你收获的不仅是宝贵的人生经历，更是新的方向和平台，到时候哪有时间喊累，而是被梦想引领着前进，痛并快乐着.hankaihankai� 5����	--['size:']	539	--['len:']	539
[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid_high:']	4	--['protoid_low']	5
[:'log']--['file':agent.lua]--['fun':client dispatch]--['protoid:']	1029	537
[:'log']--['file':agent.lua]--['fun':client dispatch]--['handler:']	14
[:'log']--['file':msgservice.lua]--['fun':lua dispatch]	4	15	PARES_CG	1029	�对比以往各种迷茫、困惑、无聊的时刻，也才真正明白，其实打败我们的根本不是口中的忙累，而是没有目标的空虚，方法不适的疲惫，以及自我放纵的不坚持。人要成长，首先要做的就是找到自己的方向和目标，寻得正确的方式方法，并为之持续坚持下去，这样你收获的不仅是宝贵的人生经历，更是新的方向和平台，到时候哪有时间喊累，而是被梦想引领着前进，痛并快乐着.hankaihankai� 5����
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	account	1	string	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	4	--['ret_int:']	502
[:'log']--['file':msgservice.lua]--['fun':read_string]	--['start_idx:']	506	--['ret_string:']	对比以往各种迷茫、困惑、无聊的时刻，也才真正明白，其实打败我们的根本不是口中的忙累，而是没有目标的空虚，方法不适的疲惫，以及自我放纵的不坚持。人要成长，首先要做的就是找到自己的方向和目标，寻得正确的方式方法，并为之持续坚持下去，这样你收获的不仅是宝贵的人生经历，更是新的方向和平台，到时候哪有时间喊累，而是被梦想引领着前进，痛并快乐着.
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	authkey	1	string	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	508	--['ret_int:']	12
[:'log']--['file':msgservice.lua]--['fun':read_string]	--['start_idx:']	520	--['ret_string:']	hankaihankai
[:'log']--['file':msgservice.lua]--['fun':PARES_CG]	testint	4	int	0
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	522	--['ret_int:']	4
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	525	--['ret_int:']	500
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	529	--['ret_int:']	800000
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	534	--['ret_int:']	98888888
[:'log']--['file':msgservice.lua]--['fun':read_int]	--['start_idx:']	538	--['ret_int:']	400000
对比以往各种迷茫、困惑、无聊的时刻，也才真正明白，其实打败我们的根本不是口中的忙累，而是没有目标的空虚，方法不适的疲惫，以及自我放纵的不坚持。人要成长，首先要做的就是找到自己的方向和目标，寻得正确的方式方法，并为之持续坚持下去，这样你收获的不仅是宝贵的人生经历，更是新的方向和平台，到时候哪有时间喊累，而是被梦想引领着前进，痛并快乐着.
hankaihankai
table: 0x7f897b7010f0
[:'log']--['file':gateserver.lua]--['fun':socket dispatch]	0	0	userdata: 0x7f897d000028	error	4	Connection reset by peer
[:'log']--['file':watchdog.lua]--['fun':lua dispatch]	0	13	socket	error	4	Connection reset by peer
socket error	4	Connection reset by peer
[:'log']--['file':gateserver.lua]--['fun':lua dispatch]	6	12	kick	4
[:0000000f] KILL self
