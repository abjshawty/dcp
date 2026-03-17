local function findItinerary(flights, start)
    local graph = {}
    for _, f in ipairs(flights) do
        local src, dst = f[1], f[2]
        if not graph[src] then graph[src] = {} end
        table.insert(graph[src], dst)
    end
    for _, dsts in pairs(graph) do table.sort(dsts) end

    local result = {}
    local function dfs(airport)
        local dsts = graph[airport] or {}
        while #dsts > 0 do
            local nxt = table.remove(dsts, 1)
            dfs(nxt)
        end
        table.insert(result, 1, airport)
    end
    dfs(start)
    if #result ~= #flights + 1 then return nil end
    return result
end

local function tableEq(a, b)
    if #a ~= #b then return false end
    for i = 1, #a do if a[i] ~= b[i] then return false end end
    return true
end

local function problem41()
    print("Problem 41:")
    local f1 = {{"SFO","HKO"},{"YYZ","SFO"},{"YUL","YYZ"},{"HKO","ORD"}}
    assert(tableEq(findItinerary(f1,"YUL"), {"YUL","YYZ","SFO","HKO","ORD"}), "assertion failed")
    local f2 = {{"SFO","COM"},{"COM","YYZ"}}
    assert(findItinerary(f2,"COM") == nil, "assertion failed")
    local f3 = {{"A","B"},{"A","C"},{"B","C"},{"C","A"}}
    assert(tableEq(findItinerary(f3,"A"), {"A","B","C","A","C"}), "assertion failed")
    print("All Tests Passed")
end

return { problem41 = problem41 }
