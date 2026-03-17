local M = {}

function M.count_bishop_pairs(bishops, m)
    local d1, d2 = {}, {}
    for _, b in ipairs(bishops) do
        local k1 = b[1] - b[2] + m
        local k2 = b[1] + b[2]
        d1[k1] = (d1[k1] or 0) + 1
        d2[k2] = (d2[k2] or 0) + 1
    end
    local count = 0
    for _, v in pairs(d1) do count = count + v*(v-1)//2 end
    for _, v in pairs(d2) do count = count + v*(v-1)//2 end
    return count
end

function M.problem68()
    print("Problem 68:")
    assert(M.count_bishop_pairs({{0,0},{1,2},{2,2},{4,0}}, 5) == 2)
    print("All Tests Passed")
end

return M
