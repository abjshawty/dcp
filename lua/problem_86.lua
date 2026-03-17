local M = {}

function M.min_parens_removal(s)
    local open, close = 0, 0
    for i = 1, #s do
        local c = s:sub(i,i)
        if c == '(' then open = open + 1
        else
            if open > 0 then open = open - 1
            else close = close + 1 end
        end
    end
    return open + close
end

function M.problem86()
    print("Problem 86:")
    assert(M.min_parens_removal("()())()") == 1)
    assert(M.min_parens_removal(")(")      == 2)
    assert(M.min_parens_removal("()()")    == 0)
    print("All Tests Passed")
end

return M
