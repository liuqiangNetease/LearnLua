//
//  LuaScriptModule.h
//  ceguiLuabind
//
//  Created by liuqiang on 2018/3/7.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#ifndef LuaScriptModule_h
#define LuaScriptModule_h

#include "ScriptModule.h"

class LuaFunctor;

class LuaScriptModule: public ScriptModule
{
public:
    friend class LuaFunctor;
    static LuaScriptModule& create(lua_State* state = 0);
    
    //! Destroys the given LuaScriptModule object.
    static void destroy(LuaScriptModule& mod);
    
 
    void executeScriptFile(const String& filename);
    
    /*!
     \brief
     Execute a script file.
     
     \param error_handler
     String containing the name of the script fuction that will be called
     if an error occurs while executing the handler function.  NB: This is
     the function passed as the error handler to lua_pcall.
     */
    void executeScriptFile(const String& filename, const String& error_handler);
    
    /*!
     \brief
     Execute a script file.
     
     \param error_handler
     integer value describing a lua registry reference to the function that
     will be called if an error occurs while executing the handler function.
     NB: This is the function passed as the error handler to lua_pcall.
     */
    void executeScriptFile(const String& filename, const int error_handler);
    
  
    //Execute a scripted global function.  The function should not take any parameters and should return an integer.
    int executeScriptGlobal(const String& function_name);
    
     //Execute a scripted global function.  The function should not take any parameters and should return an integer.
    int executeScriptGlobal(const String& function_name, const String& error_handler);

    int executeScriptGlobal(const String& function_name,const int error_handler);
    
    
    /*!
     \brief
     Execute a scripted global 'event handler' function by looking it up by
     name.
     
     \param handler_name
     String object holding the name of the scripted handler function.
     If this string contains dots '.' it will be parsed as tables containing
     a function field.  For example: 'mytable.subtable.func'
     
     \param e
     EventArgs based object that should be passed, by any appropriate means,
     to the scripted function.
     
     \return
     - true if the event was handled.
     - false if the event was not handled.
     */
    bool executeScriptedEventHandler(const String& handler_name, const EventArgs& e);
    
    /*!
     \brief
     Execute a scripted global 'event handler' function by looking it up by
     name.
     
     \param handler_name
     String object holding the name of the scripted handler function.
     If this string contains dots '.' it will be parsed as tables containing
     a function field.  For example: 'mytable.subtable.func'
     
     \param e
     EventArgs based object that should be passed, by any appropriate means,
     to the scripted function.
     
     \param error_handler
     String containing the name of the script fuction that will be called
     if an error occurs while executing the handler function.  NB: This is
     the function passed as the error handler to lua_pcall.
     
     \return
     - true if the event was handled.
     - false if the event was not handled.
     */
    bool executeScriptedEventHandler(const String& handler_name, const EventArgs& e,const String& error_handler);
    
    /*!
     \brief
     Execute a scripted global 'event handler' function by looking it up by
     name.
     
     \param handler_name
     String object holding the name of the scripted handler function.
     If this string contains dots '.' it will be parsed as tables containing
     a function field.  For example: 'mytable.subtable.func'
     
     \param e
     EventArgs based object that should be passed, by any appropriate means,
     to the scripted function.
     
     \param error_handler
     integer value describing a lua registry reference to the function that
     will be called if an error occurs while executing the handler function.
     NB: This is the function passed as the error handler to lua_pcall.
     
     \return
     - true if the event was handled.
     - false if the event was not handled.
     */
    bool executeScriptedEventHandler(const String& handler_name, const EventArgs& e,const int error_handler);
    
    /*!
     \brief
     Execute script code contained in the given CEGUI::String object.
     
     \param str
     String object holding the valid script code that should be executed.
     
     \return
     Nothing.
     */
    void executeString(const String& str);
    
    /*!
     \brief
     Execute script code contained in the given CEGUI::String object.
     
     \param str
     String object holding the valid script code that should be executed.
     
     \param error_handler
     String containing the name of the script fuction that will be called
     if an error occurs while executing the handler function.  NB: This is
     the function passed as the error handler to lua_pcall.
     
     \return
     Nothing.
     */
    void executeString(const String& str, const String& error_handler);
    
    /*!
     \brief
     Execute script code contained in the given CEGUI::String object.
     
     \param str
     String object holding the valid script code that should be executed.
     
     \param error_handler
     integer value describing a lua registry reference to the function that
     will be called if an error occurs while executing the handler function.
     NB: This is the function passed as the error handler to lua_pcall.
     
     \return
     Nothing.
     */
    void executeString(const String& str, const int error_handler);
    
//    /*************************************************************************
//     Event subscription
//     *************************************************************************/
//    /*!
//     \brief
//     Subscribes the named Event to a scripted funtion
//
//     \param target
//     The target EventSet for the subscription.
//
//     \param name
//     String object containing the name of the Event to subscribe to.
//
//     \param subscriber_name
//     String object containing the name of the script funtion that is to be
//     subscribed to the Event.
//
//     \return
//     Connection object that can be used to check the status of the Event
//     connection and to disconnect (unsubscribe) from the Event.
//     */
//    Event::Connection subscribeEvent(EventSet* target, const String& name,
//                                     const String& subscriber_name);
    
    /*!
     \brief
     Subscribes the named Event to a scripted funtion
     
     \param target
     The target EventSet for the subscription.
     
     \param name
     String object containing the name of the Event to subscribe to.
     
     \param subscriber_name
     String object containing the name of the script funtion that is to be
     subscribed to the Event.
     
     \param error_handler
     String containing the name of the script fuction that will be called
     if an error occurs while executing the handler function.  NB: This is
     the function passed as the error handler to lua_pcall.
     
     \return
     Connection object that can be used to check the status of the Event
     connection and to disconnect (unsubscribe) from the Event.
     */
//    Event::Connection subscribeEvent(EventSet* target, const String& name,
//                                     const String& subscriber_name,
//                                     const String& error_handler);
    
    /*!
     \brief
     Subscribes the named Event to a scripted funtion
     
     \param target
     The target EventSet for the subscription.
     
     \param name
     String object containing the name of the Event to subscribe to.
     
     \param subscriber_name
     String object containing the name of the script funtion that is to be
     subscribed to the Event.
     
     \param error_handler
     integer value describing a lua registry reference to the function that
     will be called if an error occurs while executing the handler function.
     NB: This is the function passed as the error handler to lua_pcall.
     
     \return
     Connection object that can be used to check the status of the Event
     connection and to disconnect (unsubscribe) from the Event.
     */
//    Event::Connection subscribeEvent(EventSet* target, const String& name,
//                                     const String& subscriber_name,
//                                     const int error_handler);
    
    /*!
     \brief
     Subscribes the specified group of the named Event to a scripted funtion.
     
     \param target
     The target EventSet for the subscription.
     
     \param name
     String object containing the name of the Event to subscribe to.
     
     \param group
     Group which is to be subscribed to.  Subscription groups are called in
     ascending order.
     
     \param subscriber_name
     String object containing the name of the script funtion that is to be
     subscribed to the Event.
     
     \return
     Connection object that can be used to check the status of the Event
     connection and to disconnect (unsubscribe) from the Event.
     */
//    Event::Connection    subscribeEvent(EventSet* target, const String& name,
//                                        Event::Group group,
//                                        const String& subscriber_name);
    
    /*!
     \brief
     Subscribes the specified group of the named Event to a scripted funtion.
     
     \param target
     The target EventSet for the subscription.
     
     \param name
     String object containing the name of the Event to subscribe to.
     
     \param group
     Group which is to be subscribed to.  Subscription groups are called in
     ascending order.
     
     \param subscriber_name
     String object containing the name of the script funtion that is to be
     subscribed to the Event.
     
     \param error_handler
     String containing the name of the script fuction that will be called
     if an error occurs while executing the handler function.  NB: This is
     the function passed as the error handler to lua_pcall.
     
     \return
     Connection object that can be used to check the status of the Event
     connection and to disconnect (unsubscribe) from the Event.
     */
//    Event::Connection subscribeEvent(EventSet* target, const String& name,
//                                     Event::Group group,
//                                     const String& subscriber_name,
//                                     const String& error_handler);
    
    /*!
     \brief
     Subscribes the specified group of the named Event to a scripted funtion.
     
     \param target
     The target EventSet for the subscription.
     
     \param name
     String object containing the name of the Event to subscribe to.
     
     \param group
     Group which is to be subscribed to.  Subscription groups are called in
     ascending order.
     
     \param subscriber_name
     String object containing the name of the script funtion that is to be
     subscribed to the Event.
     
     \param error_handler
     integer value describing a lua registry reference to the function that
     will be called if an error occurs while executing the handler function.
     NB: This is the function passed as the error handler to lua_pcall.
     
     \return
     Connection object that can be used to check the status of the Event
     connection and to disconnect (unsubscribe) from the Event.
     */
//    Event::Connection subscribeEvent(EventSet* target, const String& name,
//                                     Event::Group group,
//                                     const String& subscriber_name,
//                                     const int error_handler);
    
    /*************************************************************************
     Bindings creation / destruction
     *************************************************************************/
    /*!
     \brief
     Method called during system initialisation, prior to running any scripts
     via the ScriptModule, to enable the ScriptModule to perform any
     operations required to complete initialisation or binding of the script
     language to the gui system objects.
     
     \return
     Nothing.
     */
    void createBindings(void);
    
    /*!
     \brief
     Method called during system destruction, after all scripts have been run
     via the ScriptModule, to enable the ScriptModule to perform any
     operations required to cleanup bindings of the script language to the
     gui system objects, as set-up in the earlier createBindings call.
     
     \return
     Nothing.
     */
    void destroyBindings(void);
    
    /*************************************************************************
     Accessor type functions
     *************************************************************************/
    /*!
     \brief
     Method used to get a pointer to the lua_State that the script module is
     attached to.
     
     \return
     A pointer to the lua_State that the script module is attached to.
     */
    lua_State* getLuaState(void) const {return d_state;}
    
    /*************************************************************************
     Lua error handler related functions
     *************************************************************************/
    /*!
     \brief
     Set the name of the lua function that will be passed as the error
     handler in calls to lua_pcall, unless an alternative is specified
     in some other function call.
     
     \param error_handler_function
     Name of the lua function to be called.  This is looked up / bound on
     first usage.
     */
    void setDefaultPCallErrorHandler(const String& error_handler_function);
    
    /*!
     \brief
     Set the function that will be passed as the error handler in calls to
     lua_pcall, unless an alternative is specified in some other function
     call.
     
     \param function_reference
     Lua function registry index of the function to be called.
     */
    void setDefaultPCallErrorHandler(int function_reference);
    
    /*!
     \brief
     Return the function name string of the active error handler function.
     
     The 'active' error handler for the LuaScriptModule is either the
     default as specified by calling setDefaultPCallErrorHandler, or
     whatever might have been set up by a call to the internal
     initErrorHandlerFunc function.
     
     \note
     This function is really intended for use internally by other parts of
     the lua scripting support.  Although it could be useful elsewhere for
     advanced uses, so long as you're careful!
     */
    const String& getActivePCallErrorHandlerString() const;
    
    /*!
     \brief
     return the lua registry index of the active error handler function.
     
     The 'active' error handler for the LuaScriptModule is either the
     default as specified by calling setDefaultPCallErrorHandler, or
     whatever might have been set up by a call to the internal
     initErrorHandlerFunc function.
     \par This may return a value previously set by the user, or the value as
     bound internally by the script module for an error handler specified by
     function name.
     
     \note
     This function is really intended for use internally by other parts of
     the lua scripting support.  Although it could be useful elsewhere for
     advanced uses, so long as you're careful!
     
     \warning
     You should never call luaL_unref on the value returned by this function
     unless you created tge reference in the first place, and even then only
     after having called setDefaultPCallErrorHandler passing LUA_NOREF.
     */
    int getActivePCallErrorHandlerReference() const;
    
public:
    LuaScriptModule(lua_State* state);

    ~LuaScriptModule();
    
private:

    void setModuleIdentifierString();
    /** Init the error handler function.  Return the lua stack index that
     *  should be passed to lua_pcall.  NB: This should be called prior to
     *  pushing any function parameters onto the lua stack.
     */
    int initErrorHandlerFunc();
    /** Init the error handler function.  Return the lua stack index that
     *  should be passed to lua_pcall.  NB: This should be called prior to
     *  pushing any function parameters onto the lua stack.
     */
    int initErrorHandlerFunc(const String func_name);
    /** Init the error handler function.  Return the lua stack index that
     *  should be passed to lua_pcall.  NB: This should be called prior to
     *  pushing any function parameters onto the lua stack.
     */
    int initErrorHandlerFunc(int func);
    
    /** do any needed cleanup after having called initErrorHandlerFunc and
     * (possible) executed a script.
     *
     * NB: This probably does less than you think ;)
     */
    void cleanupErrorHandlerFunc();
    
    //! release any reference we might have made to an error handling function.
    void unrefErrorFunc();
    
    //! Implementation function that executes a scipt file.
    void executeScriptFile_impl(const String& filename,  const int err_idx, const int top);
    
    //! Implementation function that executes a global script function.
    int executeScriptGlobal_impl(const String& function_name, const int err_idx, const int top);
    
    //! Implementation function that executes a scripted event handler.
    bool executeScriptedEventHandler_impl(const String& handler_name,
                                          const EventArgs& e,
                                          const int err_idx, const int top);
    
    //! Implementation function that executes script contained in a String.
    void executeString_impl(const String& str, const int err_idx, const int top);
    
    /*************************************************************************
     Implementation Data
     *************************************************************************/
    //! true when the attached lua_State was created by this script module
    bool d_ownsState;
    //! The lua_State that this script module uses.
    lua_State* d_state;
    //! Default error handler function to pass to lua_pcall.
    String d_errFuncName;
    //! Default registry index of the function to pass to lua_pcall.
    int d_errFuncIndex;
    /** Error handler function that is currently in use (as setup via a call
     to initErrorHandlerFunc)
     */
    String d_activeErrFuncName;
    /** Registry index of the function that is currently in use (as setup via a
     call to initErrorHandlerFunc)
     */
    int d_activeErrFuncIndex;
};
#endif /* LuaScriptModule_h */
