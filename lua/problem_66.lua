local M = {}

local function toss_biased()
    return math.random() < 0.7 and 1 or 0
end

function M.unbiased_coin()
    while true do
        local a, b = toss_biased(), toss_biased()
        if a == 0 and b == 1 then return 0 end
        if a == 1 and b == 0 then return 1 end
    end
end

function M.problem66()
    print("Problem 66:")
    local counts = {0, 0}
    for _ = 1, 10000 do
        local v = M.unbiased_coin()
        counts[v+1] = counts[v+1] + 1
    end
    assert(counts[1] > 4000 and counts[2] > 4000, "bad distribution")
    print("All Tests Passed")
end

return M
