//
//  LuaFunctor.h
//  ceguiLuabind
//
//  Created by liuqiang on 2018/3/7.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#ifndef LuaFunctor_h
#define LuaFunctor_h

//#include "CEGUI/EventSet.h"
#include "Base.h"

    struct lua_State;
    class LuaScriptModule;
    
    /*!
     \brief
     Functor class used for subscribing Lua functions to GUI events
     */
    class LuaFunctor
    {
    public:
        LuaFunctor(lua_State* state, int func, int selfIndex);
        LuaFunctor(lua_State* state, const String& func, int selfIndex);
        
        LuaFunctor(lua_State* state, const int func, const int selfIndex,
                   const String& error_handler);
        LuaFunctor(lua_State* state, const String& func, const int selfIndex,
                   const String& error_handler);
        LuaFunctor(lua_State* state, const int func, const int selfIndex,
                   const int error_handler);
        LuaFunctor(lua_State* state, const String& func, const int selfIndex,
                   const int error_handler);
        
        LuaFunctor(const LuaFunctor& cp);
        ~LuaFunctor();
        
        bool operator()(const EventArgs& args) const;
        
        /*!
         \brief
         function used to subscribe any Lua function as event handler.
         References using the Lua registry.
         To be called from Lua only.
         */
//        static Event::Connection SubscribeEvent(EventSet* self,
//                                                const String& eventName,
//                                                const int funcIndex,
//                                                const int selfIndex,
//                                                const int error_handler,
//                                                lua_State* L);
        
        /*!
         \brief
         Pushes the Lua function named \param name on top of the Lua stack.
         The name may contain '.' (dots) character for (nested) table values.
         */
        static void pushNamedFunction(lua_State* L, const String& name);
        
    private:
        /*!
         \brief
         Invalidate the registry references.  This is used internally to ensure
         that the references do not get released (for example when we destroy
         a temporary object)
         */
        void invalidateLuaRefs();
        
        lua_State* L;
        mutable int index;
        int self;
        mutable bool needs_lookup;
        mutable String function_name;
        
        //! Error handler function to pass to lua_pcall.
        mutable String d_errFuncName;
        //! registry index of the function to pass to lua_pcall.
        mutable int d_errFuncIndex;
        //! signfies whether we made the reference index at d_errFuncIndex.
        mutable bool d_ourErrFuncIndex;
        
        friend class LuaScriptModule;
    };

#endif /* LuaFunctor_h */
