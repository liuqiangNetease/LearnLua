//
//  main.cpp
//  ceguiLuabind
//
//  Created by liuqiang on 2018/3/7.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#include <iostream>
#include "LuaScriptModule.h"
#include "LuaFunctor.h"
int main(int argc, const char * argv[])
{
    //const LuaScriptModule& m = LuaScriptModule::create();
    
    LuaScriptModule* pM =  new LuaScriptModule(nullptr);
    //pM->setDefaultPCallErrorHandler("DebugError");
    
    pM->executeScriptFile("main.lua");
    //pM->executeString("print(\"hello\")", "DebugError");
    
    int a = pM->executeScriptGlobal("GlobalFun", "tab.DebugError");
    
   
    a = pM->executeScriptGlobal("tab.TableFunction");
    
    a = pM->executeScriptedEventHandler("BtnClicked", EventArgs());
    
    delete pM;
//    m.executeScriptFile("main.lua");
//    LuaScriptModule::destroy(&m);
    
    return 0;
}
