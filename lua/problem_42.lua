local function subsetSum(nums, target)
    local function bt(idx, remaining, current)
        if remaining == 0 then
            local copy = {}
            for _, v in ipairs(current) do copy[#copy+1] = v end
            return copy
        end
        if idx > #nums or remaining < 0 then return nil end
        current[#current+1] = nums[idx]
        local r = bt(idx+1, remaining - nums[idx], current)
        if r then return r end
        current[#current] = nil
        return bt(idx+1, remaining, current)
    end
    return bt(1, target, {})
end

local function problem42()
    print("Problem 42:")
    local r1 = subsetSum({12,1,61,5,9,2}, 24)
    assert(r1 ~= nil, "assertion failed")
    local s = 0; for _, v in ipairs(r1) do s = s + v end
    assert(s == 24, "assertion failed")
    assert(subsetSum({1,2,3}, 100) == nil, "assertion failed")
    local r3 = subsetSum({5}, 5)
    assert(r3 ~= nil and r3[1] == 5, "assertion failed")
    print("All Tests Passed")
end

return { problem42 = problem42 }
