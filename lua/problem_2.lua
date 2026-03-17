-- productOfArrayExceptSelf returns a table where each element is the product
-- of all other elements in the input. Two passes: prefix then suffix.
-- This runs in O(n) time and O(n) space without using division.
local function productOfArrayExceptSelf(numbers)
    local n = #numbers
    local result = {}

    -- first pass: result[i] = product of all elements to the left of i
    result[1] = 1
    for i = 2, n do
        result[i] = result[i - 1] * numbers[i - 1]
    end

    -- second pass: multiply in the product of all elements to the right of i
    local suffix = 1
    for i = n, 1, -1 do
        result[i] = result[i] * suffix
        suffix = suffix * numbers[i]
    end

    return result
end

local function problem2()
    print("Problem 2:")
    local result   = productOfArrayExceptSelf({1, 2, 3, 4, 5})
    local expected = {120, 60, 40, 30, 24}
    for i = 1, #expected do
        assert(result[i] == expected[i], "assertion failed")
    end
    print("All Tests Passed")
end

return { productOfArrayExceptSelf = productOfArrayExceptSelf, problem2 = problem2 }
