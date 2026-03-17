local M = {}

function M.longest_increasing_subsequence(nums)
    local tails = {}
    for _, v in ipairs(nums) do
        local lo, hi = 1, #tails
        while lo <= hi do
            local mid = math.floor((lo + hi) / 2)
            if tails[mid] < v then lo = mid + 1 else hi = mid - 1 end
        end
        tails[lo] = v
    end
    return #tails
end

function M.problem75()
    print("Problem 75:")
    assert(M.longest_increasing_subsequence({0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}) == 6)
    assert(M.longest_increasing_subsequence({1,2,3}) == 3)
    assert(M.longest_increasing_subsequence({3,2,1}) == 1)
    print("All Tests Passed")
end

return M
