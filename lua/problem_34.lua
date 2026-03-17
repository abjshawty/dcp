local function minPalindrome(s)
    local n = #s
    local dp = {}
    for i = 1, n do
        dp[i] = {}
        for j = 1, n do dp[i][j] = 0 end
    end
    for len = 2, n do
        for i = 1, n - len + 1 do
            local j = i + len - 1
            if s:sub(i,i) == s:sub(j,j) then
                dp[i][j] = dp[i+1] and dp[i+1][j-1] or 0
            else
                local a = dp[i+1] and dp[i+1][j] or 0
                local b = dp[i][j-1] or 0
                dp[i][j] = 1 + math.min(a, b)
            end
        end
    end
    local function build(i, j)
        if i > j then return '' end
        if i == j then return s:sub(i,i) end
        if s:sub(i,i) == s:sub(j,j) then
            return s:sub(i,i) .. build(i+1, j-1) .. s:sub(j,j)
        end
        local addLeft  = s:sub(j,j) .. build(i, j-1) .. s:sub(j,j)
        local addRight = s:sub(i,i) .. build(i+1, j) .. s:sub(i,i)
        local a = dp[i+1] and dp[i+1][j] or 0
        local b = dp[i][j-1] or 0
        if a < b then return addRight end
        if b < a then return addLeft end
        return addLeft < addRight and addLeft or addRight
    end
    return build(1, n)
end

local function problem34()
    print("Problem 34:")
    assert(minPalindrome("race")   == "ecarace",  "assertion failed")
    assert(minPalindrome("google") == "elgoogle", "assertion failed")
    assert(minPalindrome("a")      == "a",        "assertion failed")
    assert(minPalindrome("ab")     == "aba",      "assertion failed")
    print("All Tests Passed")
end

return { problem34 = problem34 }
