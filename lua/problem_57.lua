local M = {}

function M.word_wrap(s, k)
    local words = {}
    for w in s:gmatch("%S+") do words[#words+1] = w end
    if #words == 0 then return nil end
    local lines = {}
    local line = words[1]
    for i = 2, #words do
        local w = words[i]
        if #line + 1 + #w <= k then
            line = line .. ' ' .. w
        else
            lines[#lines+1] = line
            line = w
        end
    end
    lines[#lines+1] = line
    for _, l in ipairs(lines) do
        if #l > k then return nil end
    end
    return lines
end

function M.problem57()
    print("Problem 57:")
    local got = M.word_wrap("the quick brown fox jumps over the lazy dog", 10)
    local exp = {"the quick","brown fox","jumps over","the lazy","dog"}
    assert(#got == #exp)
    for i = 1, #exp do assert(got[i] == exp[i]) end
    assert(M.word_wrap("toolongword", 5) == nil)
    print("All Tests Passed")
end

return M
