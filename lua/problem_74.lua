local M = {}

function M.count_in_mult_table(n, x)
    local count = 0
    for i = 1, n do
        if x % i == 0 and x // i <= n then
            count = count + 1
        end
    end
    return count
end

function M.problem74()
    print("Problem 74:")
    assert(M.count_in_mult_table(6, 12) == 4)
    assert(M.count_in_mult_table(3, 6)  == 2)
    assert(M.count_in_mult_table(1, 1)  == 1)
    print("All Tests Passed")
end

return M
