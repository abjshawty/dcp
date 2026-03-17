local function editDistance(a, b)
    local m, n = #a, #b
    local dp = {}
    for i = 0, m do
        dp[i] = {}
        for j = 0, n do
            if i == 0 then dp[i][j] = j
            elseif j == 0 then dp[i][j] = i
            else dp[i][j] = 0 end
        end
    end
    for i = 1, m do
        for j = 1, n do
            if a:sub(i,i) == b:sub(j,j) then
                dp[i][j] = dp[i-1][j-1]
            else
                dp[i][j] = 1 + math.min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
            end
        end
    end
    return dp[m][n]
end

local function problem31()
    print("Problem 31:")
    assert(editDistance("kitten", "sitting") == 3, "assertion failed")
    assert(editDistance("", "abc")           == 3, "assertion failed")
    assert(editDistance("abc", "")           == 3, "assertion failed")
    assert(editDistance("abc", "abc")        == 0, "assertion failed")
    assert(editDistance("a", "b")            == 1, "assertion failed")
    print("All Tests Passed")
end

return { problem31 = problem31 }
