-- findPairWithSum checks if any two numbers in the array sum to k.
-- It uses a hash set (table) to track numbers seen so far. For each number n,
-- it checks if the complement (k-n) was already seen — if so, a valid
-- pair exists. This runs in O(n) time and O(n) space.
local function findPairWithSum(numbers, k)
    local seen = {}
    for _, n in ipairs(numbers) do
        if seen[k - n] then -- check if the complement was seen earlier
            return true
        end
        seen[n] = true -- record this number for future iterations
    end
    return false
end

local function problem1()
    print("Problem 1:")
    assert(findPairWithSum({10, 15, 3, 7}, 17)  == true,  "assertion failed")
    assert(findPairWithSum({10, 15, 3, 7}, 100) == false, "assertion failed")
    print("All Tests Passed")
end

return { findPairWithSum = findPairWithSum, problem1 = problem1 }
