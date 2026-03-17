local M = {}

function M.max_profit(prices)
    if #prices < 2 then return 0 end
    local min_price = prices[1]
    local best = 0
    for i = 2, #prices do
        local p = prices[i]
        if p - min_price > best then best = p - min_price end
        if p < min_price then min_price = p end
    end
    return best
end

function M.problem47()
    print("Problem 47:")
    assert(M.max_profit({9,11,8,5,7,10}) == 5)
    assert(M.max_profit({1,2,3,4,5})     == 4)
    assert(M.max_profit({5,4,3,2,1})     == 0)
    print("All Tests Passed")
end

return M
