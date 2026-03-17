-- largestSumNonAdjacent returns the largest sum of non-adjacent elements.
-- Uses O(1) space DP: at each step, either skip (keep prev) or take
-- (prevPrev + current). This runs in O(n) time.
local function largestSumNonAdjacent(nums)
    local prevPrev, prev = 0, 0
    for _, n in ipairs(nums) do
        local curr = math.max(prev, prevPrev + n)
        prevPrev, prev = prev, curr
    end
    return prev
end

local function problem9()
    print("Problem 9:")
    assert(largestSumNonAdjacent({2, 4, 6, 2, 5}) == 13, "assertion failed")
    assert(largestSumNonAdjacent({5, 1, 1, 5})    == 10, "assertion failed")
    assert(largestSumNonAdjacent({})               == 0,  "assertion failed")
    assert(largestSumNonAdjacent({3})              == 3,  "assertion failed")
    print("All Tests Passed")
end

return { problem9 = problem9 }
