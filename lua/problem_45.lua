local M = {}

local function rand5() return math.random(1, 5) end

function M.rand7()
    while true do
        local n = (rand5() - 1) * 5 + (rand5() - 1)
        if n < 21 then return n % 7 + 1 end
    end
end

function M.problem45()
    print("Problem 45:")
    local counts = {}
    for i = 1, 7 do counts[i] = 0 end
    for _ = 1, 70000 do
        local v = M.rand7()
        assert(v >= 1 and v <= 7)
        counts[v] = counts[v] + 1
    end
    for i = 1, 7 do
        assert(counts[i] > 7000 and counts[i] < 13000, "bad distribution")
    end
    print("All Tests Passed")
end

return M
