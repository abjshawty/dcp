local function powerSet(nums)
    local result = {{}}
    for _, v in ipairs(nums) do
        local n = #result
        for i = 1, n do
            local sub = {}
            for _, x in ipairs(result[i]) do sub[#sub+1] = x end
            sub[#sub+1] = v
            result[#result+1] = sub
        end
    end
    return result
end

local function problem37()
    print("Problem 37:")
    assert(#powerSet({1,2,3}) == 8, "assertion failed")
    assert(#powerSet({})      == 1, "assertion failed")
    assert(#powerSet({1})     == 2, "assertion failed")
    print("All Tests Passed")
end

return { problem37 = problem37 }
