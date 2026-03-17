local M = {}

local function digit_sum(n)
    local s = 0
    while n > 0 do s = s + (n % 10); n = n // 10 end
    return s
end

function M.nth_perfect_number(n)
    local count, num = 0, 0
    while count < n do
        num = num + 1
        if digit_sum(num) == 10 then count = count + 1 end
    end
    return num
end

function M.problem70()
    print("Problem 70:")
    assert(M.nth_perfect_number(1) == 19)
    assert(M.nth_perfect_number(2) == 28)
    assert(M.nth_perfect_number(3) == 37)
    print("All Tests Passed")
end

return M
