#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "skynet.h"

static int
_hkwrite_int(lua_State *L) 
{//-2147483648~2147483647
	unsigned int int_value = luaL_checknumber(L,1);

	// printf("[:'log']--['file':%s]--['fun':%s]--['int_value':%u]\n","lua_hksend.c","_hkwrite_int",int_value);
	unsigned int int_byte = 0;
	unsigned int int_arr[4];

	for(int i=0;i<4;i++)
	{
		bool is_break = false;
		if(int_value<256)
		{
			is_break = true;
		}

		unsigned int v = int_value & 255;
		if(!is_break)
		{
			int_value = int_value >> 8;
		}

		int_arr[int_byte] = v;
		int_byte++;
		// printf("[:'log']--['file':%s]--['fun':%s]--['v':%d]--['int_byte':%d]\n","lua_hksend.c","_hkwrite_int",v,int_byte);
		
		if(is_break)
		{
			break;
		}
	}

	char int2char_byte[2];
	memcpy(int2char_byte,&int_byte,1);
	char char_0[2] = {'0'};
	char char_1[2] = {'0'};
	char char_2[2] = {'0'};
	char char_3[2] = {'0'};
	//记录空字符的位置
	char char_null[2];
	int kong = 128;
	int flag = 1;



	for(int i = 0;i<int_byte;i++)
	{
		// printf("[:'log']--['file':%s]--['fun':%s]--['int_arr[%d]':%d]--['int_byte':%d]\n","lua_hksend.c","_hkwrite_int",i,int_arr[i],int_byte);
		if(int_arr[i]==0)
		{
			kong = kong | flag;
			flag = flag << 1;
			continue;
			// printf("[:'log']--['file':%s]--['fun':%s]--['buf_write[%d]':%s]--['int_byte':%d]\n","lua_hksend.c","_hkwrite_int",write_start,buf_write[write_start],int_byte);
		}

		flag = flag << 1;
		if(i==0)
		{
			memcpy(char_0,&int_arr[i],1);
			continue;
		}
		else if(i==1)
		{
			memcpy(char_1,&int_arr[i],1);
			continue;
		}
		else if(i==2)
		{
			memcpy(char_2,&int_arr[i],1);
			continue;
		}
		else if(i==3)
		{
			memcpy(char_3,&int_arr[i],1);
			continue;
		}
		
	}

	memcpy(char_null,&kong,1);//"\0"位置

	lua_pushstring(L,int2char_byte);
	lua_pushstring(L,char_0);
	lua_pushstring(L,char_1);
	lua_pushstring(L,char_2);
	lua_pushstring(L,char_3);
	lua_pushstring(L,char_null);
	// printf("[:'log']--['file':%s]--['fun':%s]--['char_0':%s]--['char_1':%s]--['char_2':%s]--['char_3':%s]\n","lua_hksend.c","_hkwrite_int",char_0,char_1,char_2,char_3);
	return 6;
}


int
luaopen_hksend(lua_State *L) {
	luaL_checkversion(L);

	luaL_Reg l[] = {
		{ "hkwrite_int" , _hkwrite_int },
		{ NULL, NULL },
	};

	luaL_newlibtable(L, l);

	lua_getfield(L, LUA_REGISTRYINDEX, "skynet_context");
	struct skynet_context *ctx = lua_touserdata(L,-1);
	if (ctx == NULL) {
		return luaL_error(L, "Init skynet context first");
	}

	luaL_setfuncs(L,l,1);

	return 1;
}