-- wordBreak reconstructs s from words using backtracking with memoisation.
-- Returns any valid split as a table, or nil if impossible.
local function wordBreak(s, words)
    local wordSet = {}
    for _, w in ipairs(words) do wordSet[w] = true end
    local failed = {}

    local function backtrack(start)
        if start > #s then return {} end  -- fully consumed (1-indexed)
        if failed[start] then return nil end
        for finish = start, #s do
            local word = s:sub(start, finish)
            if wordSet[word] then
                local rest = backtrack(finish + 1)
                if rest ~= nil then
                    local result = { word }
                    for _, w in ipairs(rest) do result[#result+1] = w end
                    return result
                end
            end
        end
        failed[start] = true
        return nil
    end

    return backtrack(1)
end

local function tablesEqual(a, b)
    if #a ~= #b then return false end
    for i = 1, #a do if a[i] ~= b[i] then return false end end
    return true
end

local function problem22()
    print("Problem 22:")
    local r1 = wordBreak("thequickbrownfox", {"quick","brown","the","fox"})
    assert(tablesEqual(r1, {"the","quick","brown","fox"}), "assertion failed")
    local r2 = wordBreak("bedbathandbeyond", {"bed","bath","bedbath","and","beyond"})
    assert(r2 ~= nil, "assertion failed")
    assert(wordBreak("xyz", {"a","b"}) == nil, "assertion failed")
    print("All Tests Passed")
end

return { problem22 = problem22 }
