People = {}

// function 也可以这样写
--People.sayHi = function()
--    print("People say hi")
--end

function People.sayHi()
    print("People say hi")
end

//复制表
function clone(tab)
    local ins = {}
    for key, var in pairs(tab) do
        ins[key] = var
    end
    return ins
end


local p = clone(People)
p.sayHi()  //控制台输出 People say hi



//如何带参数
People.new = function(name)
    local self = clone(People)
    self.name = name
    return self
end

fuction People.sayHi(self)
    print("People say Hi:" -- self.name)

local p = People.new("zhangsan")
p.sayHi(p) //等价于。p:sayHi()



//类继承

function copy(dest, tab)
    for key, var in pairs(tab) do
        dest[key] = var
    end
end

Man = {}
function Man.new(name)
    local self = People.new(name)
    copy(self,Man)
    return self
end

Man.sayHello = function()
    print("Man say hello")
end

Man.sayHi = function(self)
    print("Man sayHi " .. self.name)
end


local m = Man.new("lisi")
m:sayHello()
m:sayHi()


//函数闭包方式实现面向对象
function Animal(name)
    local self = {}
    local function init()
          self.name = name
    end
    self.sayHi = function()
    print("Hello "..self.name)
    end

    init()
    return self
end

local a = Animai("gou")
p.sayHi()

//类继承
function Monkey(name)
    local self = Animal(name)
    self.sayHello = function()
        print("Hi "..self.name)
    end
    return self
end

local m = Monkey("monkey")
m:sayHello()
m:sayHi()
