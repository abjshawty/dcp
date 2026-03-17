local M = {}

function M.can_partition(nums)
    local total = 0
    for _, v in ipairs(nums) do total = total + v end
    if total % 2 ~= 0 then return false end
    local target = total // 2
    local dp = {}
    for i = 0, target do dp[i] = false end
    dp[0] = true
    for _, v in ipairs(nums) do
        for j = target, v, -1 do
            dp[j] = dp[j] or dp[j - v]
        end
    end
    return dp[target]
end

function M.problem60()
    print("Problem 60:")
    assert(    M.can_partition({15,5,20,10,35,15,10}))
    assert(not M.can_partition({15,5,20,10,35}))
    assert(    M.can_partition({1,5,11,5}))
    print("All Tests Passed")
end

return M
