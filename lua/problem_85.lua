local M = {}

function M.select_by_bit(x, y, b)
    return x * b + y * (1 - b)
end

function M.problem85()
    print("Problem 85:")
    assert(M.select_by_bit(10, 20, 1) == 10)
    assert(M.select_by_bit(10, 20, 0) == 20)
    assert(M.select_by_bit(5,  7,  1) == 5)
    print("All Tests Passed")
end

return M
