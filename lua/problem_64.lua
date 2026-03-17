local M = {}

function M.knight_tours(n)
    local board = {}
    for i = 1, n do board[i] = {}; for j = 1, n do board[i][j] = false end end
    local moves = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}}
    local count = 0
    local function dfs(r, c, visited)
        if visited == n * n then count = count + 1; return end
        for _, m in ipairs(moves) do
            local nr, nc = r + m[1], c + m[2]
            if nr >= 1 and nr <= n and nc >= 1 and nc <= n and not board[nr][nc] then
                board[nr][nc] = true
                dfs(nr, nc, visited + 1)
                board[nr][nc] = false
            end
        end
    end
    for r = 1, n do for c = 1, n do
        board[r][c] = true; dfs(r, c, 1); board[r][c] = false
    end end
    return count
end

function M.problem64()
    print("Problem 64:")
    assert(M.knight_tours(1) == 1)
    assert(M.knight_tours(2) == 0)
    assert(M.knight_tours(3) == 0)
    print("All Tests Passed")
end

return M
