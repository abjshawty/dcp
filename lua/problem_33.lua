local function insortedInsert(sorted, v)
    local lo, hi = 1, #sorted + 1
    while lo < hi do
        local mid = math.floor((lo + hi) / 2)
        if sorted[mid] < v then lo = mid + 1 else hi = mid end
    end
    table.insert(sorted, lo, v)
end

local function runningMedian(nums)
    local result = {}
    local sorted = {}
    for _, v in ipairs(nums) do
        insortedInsert(sorted, v)
        local n = #sorted
        if n % 2 == 1 then
            result[#result + 1] = sorted[math.floor(n / 2) + 1]
        else
            result[#result + 1] = (sorted[n / 2] + sorted[n / 2 + 1]) / 2.0
        end
    end
    return result
end

local function tableEq(a, b)
    if #a ~= #b then return false end
    for i = 1, #a do if a[i] ~= b[i] then return false end end
    return true
end

local function problem33()
    print("Problem 33:")
    local got = runningMedian({2,1,5,7,2,0,5})
    local exp = {2, 1.5, 2, 3.5, 2, 2, 2}
    assert(tableEq(got, exp), "assertion failed")
    print("All Tests Passed")
end

return { problem33 = problem33 }
