local function isMatch(s, p)
    local m, n = #s, #p
    local dp = {}
    for i = 0, m do
        dp[i] = {}
        for j = 0, n do dp[i][j] = false end
    end
    dp[m][n] = true

    for j = n - 1, 0, -1 do
        if j + 1 < n and p:sub(j + 2, j + 2) == '*' then
            dp[m][j] = dp[m][j + 2]
        end
    end

    for i = m - 1, 0, -1 do
        for j = n - 1, 0, -1 do
            local pj = p:sub(j + 1, j + 1)
            local si = s:sub(i + 1, i + 1)
            local firstMatch = pj == '.' or pj == si
            if j + 1 < n and p:sub(j + 2, j + 2) == '*' then
                dp[i][j] = dp[i][j + 2] or (firstMatch and dp[i + 1][j])
            else
                dp[i][j] = firstMatch and dp[i + 1][j + 1]
            end
        end
    end
    return dp[0][0]
end

local function problem25()
    print("Problem 25:")
    assert(isMatch("ray",     "ra.")   == true,  "assertion failed")
    assert(isMatch("raymond", "ra.")   == false, "assertion failed")
    assert(isMatch("chat",    ".*at")  == true,  "assertion failed")
    assert(isMatch("chats",   ".*at")  == false, "assertion failed")
    assert(isMatch("",        "a*")    == true,  "assertion failed")
    assert(isMatch("aaa",     "a*")    == true,  "assertion failed")
    assert(isMatch("ab",      ".*")    == true,  "assertion failed")
    print("All Tests Passed")
end

return { problem25 = problem25 }
