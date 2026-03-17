-- firstMissingPositive finds the smallest positive integer absent from numbers.
-- It uses the array itself as a hash map: for each value v in [1..n], it places
-- v at index v-1. After rearranging, the first index i where numbers[i] != i+1
-- reveals the answer i+1. This runs in O(n) time and O(1) extra space.
-- Note: Lua arrays are 1-indexed, so "home" index for value v is v (not v-1).
local function firstMissingPositive(numbers)
    local n = #numbers

    -- place each value v into its "home" index v, if 1 <= v <= n
    for i = 1, n do
        while numbers[i] >= 1 and numbers[i] <= n and numbers[numbers[i]] ~= numbers[i] do
            local j = numbers[i]
            numbers[i], numbers[j] = numbers[j], numbers[i] -- swap into place
        end
    end

    -- first index whose value is wrong reveals the missing positive
    for i = 1, n do
        if numbers[i] ~= i then
            return i
        end
    end

    return n + 1 -- all of 1..n are present
end

local function problem4()
    print("Problem 4:")
    assert(firstMissingPositive({3, 4, -1, 1}) == 2, "assertion failed")
    assert(firstMissingPositive({1, 2, 0})      == 3, "assertion failed")
    assert(firstMissingPositive({1, 2, 3})      == 4, "assertion failed")
    assert(firstMissingPositive({7, 8, 9})      == 1, "assertion failed")
    print("All Tests Passed")
end

return { firstMissingPositive = firstMissingPositive, problem4 = problem4 }
