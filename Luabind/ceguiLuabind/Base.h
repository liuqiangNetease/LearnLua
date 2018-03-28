//
//  Base.h
//  ceguiLuabind
//
//  Created by liuqiang on 2018/3/7.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#ifndef Base_h
#define Base_h

#include <vector>
#include <map>
#include <string>
typedef std::string String;

typedef unsigned int uint;
typedef unsigned char uint8;
typedef        uint8    utf8;
//typedef        uint16    utf16;  // removed typedef to prevent usage, as utf16 is not supported (yet)
typedef unsigned int uint32;
typedef        uint32    utf32;

// include Lua libs and tolua++
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

//#include "tolua++.h"

class EventArgs
{
public:
  
    EventArgs(void) : handled(0) {}
    virtual ~EventArgs(void) {}

    //! handlers should increment this if they handled the event.
    uint handled;
};

#endif /* Base_h */
