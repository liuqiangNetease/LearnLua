//
//  ScriptModule.h
//  ceguiLuabind
//
//  Created by liuqiang on 2018/3/7.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#ifndef ScriptModule_h
#define ScriptModule_h

#include "Base.h"


class ScriptModule
{
public:
    ScriptModule(void);
    virtual ~ScriptModule(void) {}
   
  
    virtual    void    executeScriptFile(const String& filename)    = 0;
    
    
    /*!
     \brief
     Execute a scripted global function.  The function should not take any parameters and should return an integer.     
     \param function_name
     String object holding the name of the function, in the global script environment, that
     is to be executed.
     \return
     The integer value returned from the script function.
     */
    virtual int    executeScriptGlobal(const String& function_name)    = 0;
    
    
    /*!
     \brief
     Execute a scripted global 'event handler' function.  The function should take some kind of EventArgs like parameter
     that the concrete implementation of this function can create from the passed EventArgs based object.  The function
     should not return anything.
     
     \param handler_name
     String object holding the name of the scripted handler function.
     
     \param e
     EventArgs based object that should be passed, by any appropriate means, to the scripted function.
     
     \return
     - true if the event was handled.
     - false if the event was not handled.
     */
    virtual    bool    executeScriptedEventHandler(const String& handler_name, const EventArgs& e)        = 0;
    
    
    /*!
     \brief
     Execute script code contained in the given CEGUI::String object.
     
     \param str
     String object holding the valid script code that should be executed.
     
     \return
     Nothing.
     */
    virtual void executeString(const String& str) = 0;
    
    
    /*!
     \brief
     Method called during system initialisation, prior to running any scripts via the ScriptModule, to enable the ScriptModule
     to perform any operations required to complete initialisation or binding of the script language to the gui system objects.
     
     \return
     Nothing.
     */
    virtual void createBindings(void) {}
    
    
    /*!
     \brief
     Method called during system destruction, after all scripts have been run via the ScriptModule, to enable the ScriptModule
     to perform any operations required to cleanup bindings of the script language to the gui system objects, as set-up in the
     earlier createBindings call.
     
     \return
     Nothing.
     */
    virtual void destroyBindings(void) {}
    
    /*!
     \brief
     Return identification string for the ScriptModule.  If the internal id string has not been
     set by the ScriptModule creator, a generic string of "Unknown scripting module" will be returned.
     
     \return
     String object holding a string that identifies the ScriptModule in use.
     */
    const String& getIdentifierString() const;
    
   
//    virtual Event::Connection    subscribeEvent(EventSet* target, const String& name, const String& subscriber_name) = 0;
//   
//    virtual Event::Connection    subscribeEvent(EventSet* target, const String& name, Event::Group group, const String& subscriber_name) = 0;
  
    
protected:
    //! String that holds some id information about the module.
    String d_identifierString;
};


/*!
 \brief
 Functor class used for binding named script functions to events
 */
class  ScriptFunctor
{
public:
    ScriptFunctor(const String& functionName) : scriptFunctionName(functionName) {}
    ScriptFunctor(const ScriptFunctor& obj) : scriptFunctionName(obj.scriptFunctionName) {}
    bool    operator()(const EventArgs& e) const;
    
private:
    // no assignment possible
    ScriptFunctor& operator=(const ScriptFunctor& rhs);
    
    const String    scriptFunctionName;
};

#endif /* ScriptModule_h */
