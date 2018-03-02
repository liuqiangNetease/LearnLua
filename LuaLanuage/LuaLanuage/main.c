//
//  main.c
//  LuaLanuage
//
//  Created by 刘强 on 2018/2/16.
//  Copyright © 2018年 刘强. All rights reserved.
//

#include <stdio.h>
#include "lua.h"
#include "lprefix.h"


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

//int main (int argc, char **argv) {
//  int status, result;
//  lua_State *L = luaL_newstate();  /* create state */
//  if (L == NULL) {
//    l_message(argv[0], "cannot create state: not enough memory");
//    return EXIT_FAILURE;
//  }
//  lua_pushcfunction(L, &pmain);  /* to call 'pmain' in protected mode */
//  lua_pushinteger(L, argc);  /* 1st argument */
//  lua_pushlightuserdata(L, argv); /* 2nd argument */
//  status = lua_pcall(L, 2, 1, 0);  /* do the call */
//  result = lua_toboolean(L, -1);  /* get result */
//  report(L, status);
//  lua_close(L);
//  return (result && status == LUA_OK) ? EXIT_SUCCESS : EXIT_FAILURE;
//}

//lesson 1 c visit lua global
//int main (int argc, char **argv) {
//    lua_State * L = luaL_newstate();
//    luaL_openlibs(L);
//    dofile(L, "main.lua");
//    //dostring(L, "print( \"Hello lua\" )", "Myscript");
//
//    //c获取lua全局变量
//    lua_getglobal(L, "name");//把全局变量name压入lua堆栈
//    lua_getglobal(L, "version");
////    if (lua_isstring(L, -1)) {
////        printf("%s\n", lua_tostring(L, -1));//获取lua堆栈顶部元素
////    }
//    //也可以用数字
//    if (lua_isnumber(L, -1)) {
//        printf("%g\n", lua_tonumber(L, -1));//获取lua堆栈顶部元素
//    }
//    if (lua_isstring(L, -2)) {
//        printf("%s\n", lua_tostring(L, -2));//获取lua堆栈顶部下一个元素
//    }
//
//    lua_pop(L, 2); //清空堆栈 从顶部开始pop
//    lua_close(L);
//    return 0;
//}
////lesson 2 c visit lua table
//int main (int argc, char **argv) {
//    lua_State * L = luaL_newstate();
//    luaL_openlibs(L);
//    dofile(L, "main.lua");
//
//    //把people对象压入堆栈
//    lua_getglobal(L, "people");
//    //把people对象 field（成员）name 压入堆栈
//    lua_getfield(L, 1, "name"); //1表示堆栈索引 name 是field（成员）
//
//    if (lua_isstring(L, -1)) {
//        printf("name= %s\n", lua_tostring(L, -1));
//    }
//
//    lua_pop(L, 2);
//
//
//    lua_close(L);
//    return 0;
//}
//lesson 2.2 c visit lua table
int main (int argc, char **argv) {
    lua_State * L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "main.lua");
    

    //把people对象压入堆栈
    lua_getglobal(L, "people");
    lua_pushstring(L, "name");
    
    //table is now at -2 (key is at -1). lua_gettable now pops the key off
    //the stack and then puts the data found at the key location on the stack
    lua_gettable(L, -2);

    if (lua_isstring(L, -1)) {
        printf("name= %s\n", lua_tostring(L, -1));
    }

    lua_pop(L, 1);


    lua_close(L);
    return 0;
}

//lesson 3 c visit lua function
//int main (int argc, char **argv) {
//    lua_State * L = luaL_newstate();
//    luaL_openlibs(L);
//    dofile(L, "main.lua");
//
//    lua_getglobal(L, "main");
//    //lua_call 调用完成，把堆栈清空，并把返回值放到堆栈顶部
//    lua_call(L,0,0);// 第一个0 表示没有参数 第二个0 表示0个返回值
//    lua_pop(L, 1);//把堆栈顶部的函数返回值pop出堆栈，此时堆栈是空
//
//    if(!lua_isstring(L, -1))
//        printf("stack is empty\n");
//
//
//
//    lua_getglobal(L, "MulParaFunc");
//    lua_pushstring(L, "zhangsan");
//calling the function with parameters to set the number of parameters in
//the lua func and how many return values it returns. Puts the result at
//the top of the stack.
//    lua_call(L, 1, 1);//调用完成时函数返回值放在堆栈顶部
//
//    if (lua_isstring(L, -1))//判定堆栈顶部的函数返回值是非是string
//    {
//        printf("%s\n", lua_tostring(L, -1));//打印函数返回值
//    }
//
//    lua_pop(L, 1);
//
//    lua_close(L);
//    return 0;
//}
//lesson 4 lua visit c
int sayHello(lua_State* L)
{
    printf("c say: Hello\n");
    return 0;//返回值个数 result count
}

int getString(lua_State* L)
{
    //lua_pushstring(L, "test");
    const char* name = luaL_checkstring(L, -1);//拿到lua堆栈顶部元素的值
    char buf[128];
    memset(buf, 0, 128);
    sprintf(buf, "Hello %s", name);
    
    lua_pushstring(L, buf);//把buf压入堆栈
    
    return 1;//1个返回值
}

int getNumber(lua_State* L)
{
    const char* name = luaL_checkstring(L, -2);//拿到lua堆栈顶部下一个元素的值
    const char* name2 = luaL_checkstring(L, -1);//拿到lua堆栈顶部元素的值
    char buf[128];
    memset(buf, 0, 128);
    sprintf(buf, "Hello %s %s", name, name2);
    
    lua_pushstring(L, buf);//把buf压入堆栈
    return 1;
}

//int main (int argc, char **argv) {
//    lua_State * L = luaL_newstate();
//    luaL_openlibs(L);
//
//    lua_register(L, "sayHello", sayHello);
//    lua_register(L, "getString", getString);
//    lua_register(L, "getNumber", getNumber);
//
//    luaL_dofile(L, "luaCallC.lua");
//
//    lua_close(L);
//    return 0;
//}
