-- minCostPaint returns the minimum cost to paint N houses with K colors
-- such that no two adjacent houses share the same color.
-- Uses bottom-up DP. This runs in O(N*K) time.
local function minCostPaint(costs)
    if #costs == 0 then return 0 end
    local n = #costs
    local k = #costs[1]
    -- deep copy
    local dp = {}
    for i = 1, n do
        dp[i] = {}
        for c = 1, k do dp[i][c] = costs[i][c] end
    end

    for i = 2, n do
        for c = 1, k do
            local minPrev = math.huge
            for p = 1, k do
                if p ~= c and dp[i-1][p] < minPrev then minPrev = dp[i-1][p] end
            end
            dp[i][c] = dp[i][c] + minPrev
        end
    end

    local best = math.huge
    for _, v in ipairs(dp[n]) do if v < best then best = v end end
    return best
end

local function problem19()
    print("Problem 19:")
    local costs = {{17,2,17},{16,16,5},{14,3,19}}
    assert(minCostPaint(costs)       == 10, "assertion failed")
    assert(minCostPaint({{1,2,3}})   == 1,  "assertion failed")
    print("All Tests Passed")
end

return { problem19 = problem19 }
