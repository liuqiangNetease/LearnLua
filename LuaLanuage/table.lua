--table
Config = { hello = "hello lua", world = "lua"}
Config.words = "Hello"
Config.num = 100
Config["name"] = "Zhangsan"

print(Config.name)
print(Config["words"])
print(Config.hello)

for key, var in pairs(Config) do
    print(key, var)
end


--数组  注意：数组的索引是从1开始
arr = {1,2,3,"hello"}
for key, var in pairs(arr) do
    print(key, var)
end

--lua api  可以在lua官网reference Manual中找到
arr1 = {}
for var=1, 100 do
    table.insert(arr1,1,var)
end

for key, var in pairs(arr1) do
    print(key, var)
end

print(table.maxn(arr1))  // 数组长度



