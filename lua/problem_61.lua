local M = {}

function M.fast_pow(x, y)
    if y == 0 then return 1 end
    if y < 0  then return 0 end
    local half = M.fast_pow(x, math.floor(y / 2))
    if y % 2 == 0 then return half * half
    else return half * half * x end
end

function M.problem61()
    print("Problem 61:")
    assert(M.fast_pow(2, 10) == 1024)
    assert(M.fast_pow(3, 0)  == 1)
    assert(M.fast_pow(5, 3)  == 125)
    print("All Tests Passed")
end

return M
