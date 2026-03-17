-- maxSubarrayOfSizeK returns the max value of each sliding window of size k.
-- Uses a monotonic deque (1-based indices) in decreasing value order.
-- This runs in O(n) time and O(k) space.
local function maxSubarrayOfSizeK(nums, k)
    local deque = {}  -- stores 1-based indices; front is current window max
    local result = {}

    for i = 1, #nums do
        -- remove indices outside the window
        while #deque > 0 and deque[1] < i - k + 1 do
            table.remove(deque, 1)
        end
        -- remove smaller elements from the back
        while #deque > 0 and nums[deque[#deque]] < nums[i] do
            table.remove(deque)
        end
        deque[#deque+1] = i

        if i >= k then  -- window is full
            result[#result+1] = nums[deque[1]]
        end
    end
    return result
end

local function tablesEqual(a, b)
    if #a ~= #b then return false end
    for i = 1, #a do if a[i] ~= b[i] then return false end end
    return true
end

local function problem18()
    print("Problem 18:")
    assert(tablesEqual(maxSubarrayOfSizeK({10,5,2,7,8,7}, 3), {10,7,8,8}), "assertion failed")
    assert(tablesEqual(maxSubarrayOfSizeK({1,2,3}, 1), {1,2,3}),           "assertion failed")
    print("All Tests Passed")
end

return { problem18 = problem18 }
