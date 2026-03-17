local M = {}

local function rand7() return math.random(1, 7) end

function M.rand5()
    while true do
        local v = rand7()
        if v <= 5 then return v end
    end
end

function M.problem71()
    print("Problem 71:")
    local counts = {}
    for i = 1, 5 do counts[i] = 0 end
    for _ = 1, 50000 do
        local v = M.rand5()
        assert(v >= 1 and v <= 5)
        counts[v] = counts[v] + 1
    end
    for i = 1, 5 do
        assert(counts[i] > 7000 and counts[i] < 13000, "bad distribution")
    end
    print("All Tests Passed")
end

return M
