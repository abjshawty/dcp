local M = {}

function M.phone_letters(mapping, digits)
    if #digits == 0 then return {""} end
    local result = {}
    local first = mapping[digits:sub(1,1)]
    local rest = M.phone_letters(mapping, digits:sub(2))
    for _, letter in ipairs(first) do
        for _, r in ipairs(rest) do
            result[#result+1] = letter .. r
        end
    end
    return result
end

function M.problem81()
    print("Problem 81:")
    local m = {['2']={"a","b","c"}, ['3']={"d","e","f"}}
    local got = M.phone_letters(m, "23")
    assert(#got == 9)
    print("All Tests Passed")
end

return M
