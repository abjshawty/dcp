-- staircase returns the number of unique ways to climb n steps
-- when you can take any step size from the steps table.
-- Uses bottom-up DP. This runs in O(n * |steps|) time and O(n) space.
local function staircase(n, steps)
    local ways = {}
    for i = 0, n do ways[i] = 0 end
    ways[0] = 1
    for i = 1, n do
        for _, s in ipairs(steps) do
            if i - s >= 0 then
                ways[i] = ways[i] + ways[i - s]
            end
        end
    end
    return ways[n]
end

local function problem12()
    print("Problem 12:")
    assert(staircase(4, {1, 2})    == 5, "assertion failed")
    assert(staircase(4, {1, 3, 5}) == 3, "assertion failed")
    assert(staircase(0, {1, 2})    == 1, "assertion failed")
    assert(staircase(1, {1, 2})    == 1, "assertion failed")
    print("All Tests Passed")
end

return { problem12 = problem12 }
