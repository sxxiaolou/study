#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "skynet.h"

char buf_write[65535];
int write_start = 0;

static int
_hksend_start(lua_State *L)
{
	printf("[:'log']--['file':%s]--['fun':%s]\n","lua_hksend.c","_hksend_start");
	memset(buf_write,0,sizeof(char)*65535);
	write_start = 0;
	return 0;
}

static int
_hksend_end(lua_State *L)
{
	printf("[:'log']--['file':%s]--['fun':%s]--['write_start':%d]\n","lua_hksend.c","_hksend_end",write_start);
	// printf("[:'log']--['file':%s]--['fun':%s]--['buf_write':%s]\n","lua_hksend.c","_hksend_end",buf_write);
	char ret_char[write_start];
	memcpy(ret_char,buf_write,write_start);
	// printf("[:'log']--['file':%s]--['fun':%s]--['ret_char':%s]\n","lua_hksend.c","_hksend_end",ret_char);
	lua_pushstring(L,ret_char);
	return 1;
}

static int
_hkwrite_int(lua_State *L) 
{//-2147483648~2147483647
	unsigned int int_value = luaL_checknumber(L,1);

	printf("[:'log']--['file':%s]--['fun':%s]--['int_value':%u]\n","lua_hksend.c","_hkwrite_int",int_value);
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
		printf("[:'log']--['file':%s]--['fun':%s]--['v':%d]--['int_byte':%d]\n","lua_hksend.c","_hkwrite_int",v,int_byte);
		
		if(is_break)
		{
			break;
		}
	}
	memcpy(buf_write+write_start,&int_byte,1);
	write_start++;

	for(int i = 0;i<int_byte;i++)
	{
		// printf("[:'log']--['file':%s]--['fun':%s]--['int_arr[%d]':%d]--['int_byte':%d]\n","lua_hksend.c","_hkwrite_int",i,int_arr[i],int_byte);
		if(int_arr[i]==0)
		{
			// memcpy(buf_write+write_start,&int_arr[i],1);
			buf_write[write_start] = '$';
			// printf("[:'log']--['file':%s]--['fun':%s]--['buf_write[%d]':%s]--['int_byte':%d]\n","lua_hksend.c","_hkwrite_int",write_start,buf_write[write_start],int_byte);
		}
		else
		{
			memcpy(buf_write+write_start,&int_arr[i],1);
		}
		
		write_start++;
	}
	return 0;
}

static int
_hkwrite_string(lua_State *L) 
{
	const char *str_value = luaL_checkstring(L,1);
	int str_len = luaL_checknumber(L,2);
	printf("[:'log']--['file':%s]--['fun':%s]--['str_value':%s]--['str_len':%d]\n","lua_hksend.c","_hkwrite_string",str_value,str_len);
	memcpy(buf_write+write_start,str_value,str_len);
	write_start += str_len;
	return 0;
}


int
luaopen_hksend(lua_State *L) {
	luaL_checkversion(L);

	luaL_Reg l[] = {
		{ "hksend_start" , _hksend_start },
		{ "hksend_end" , _hksend_end },
		{ "hkwrite_int" , _hkwrite_int },
		{ "hkwrite_string" , _hkwrite_string },
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