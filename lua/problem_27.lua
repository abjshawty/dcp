local function isBalanced(s)
    local match = { [')'] = '(', [']'] = '[', ['}'] = '{' }
    local stack = {}
    for i = 1, #s do
        local c = s:sub(i, i)
        if c == '(' or c == '[' or c == '{' then
            stack[#stack + 1] = c
        elseif c == ')' or c == ']' or c == '}' then
            if #stack == 0 or stack[#stack] ~= match[c] then return false end
            stack[#stack] = nil
        end
    end
    return #stack == 0
end

local function problem27()
    print("Problem 27:")
    assert(isBalanced("([])[]({})")  == true,  "assertion failed")
    assert(isBalanced("([)]")        == false, "assertion failed")
    assert(isBalanced("(((()")       == false, "assertion failed")
    assert(isBalanced("")            == true,  "assertion failed")
    assert(isBalanced("{[]}")        == true,  "assertion failed")
    print("All Tests Passed")
end

return { problem27 = problem27 }
