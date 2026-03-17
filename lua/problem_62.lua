local M = {}

function M.count_paths(n, m)
    local dp = {}
    for i = 1, n do
        dp[i] = {}
        for j = 1, m do dp[i][j] = 1 end
    end
    for i = 2, n do
        for j = 2, m do
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
        end
    end
    return dp[n][m]
end

function M.problem62()
    print("Problem 62:")
    assert(M.count_paths(2, 2) == 2)
    assert(M.count_paths(5, 5) == 70)
    assert(M.count_paths(1, 1) == 1)
    print("All Tests Passed")
end

return M
