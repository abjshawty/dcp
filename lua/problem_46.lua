local M = {}

function M.longest_palindromic_substring(s)
    if #s == 0 then return "" end
    local best_start, best_len = 1, 1
    local function expand(l, r)
        while l >= 1 and r <= #s and s:sub(l,l) == s:sub(r,r) do
            if r - l + 1 > best_len then
                best_start = l; best_len = r - l + 1
            end
            l = l - 1; r = r + 1
        end
    end
    for i = 1, #s do
        expand(i, i)
        expand(i, i + 1)
    end
    return s:sub(best_start, best_start + best_len - 1)
end

function M.problem46()
    print("Problem 46:")
    assert(M.longest_palindromic_substring("aabcdcb") == "bcdcb")
    assert(M.longest_palindromic_substring("bananas") == "anana")
    assert(M.longest_palindromic_substring("a")       == "a")
    assert(M.longest_palindromic_substring("cbbd")    == "bb")
    print("All Tests Passed")
end

return M
