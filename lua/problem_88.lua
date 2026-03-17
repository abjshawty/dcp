local M = {}

function M.int_divide(a, b)
    local q = 0
    while a >= b do a = a - b; q = q + 1 end
    return q
end

function M.problem88()
    print("Problem 88:")
    assert(M.int_divide(10,  3)  == 3)
    assert(M.int_divide(7,   2)  == 3)
    assert(M.int_divide(100, 10) == 10)
    assert(M.int_divide(1,   1)  == 1)
    print("All Tests Passed")
end

return M
