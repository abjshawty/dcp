local M = {}

function M.count_islands(grid)
    local rows = #grid; local cols = #grid[1]
    local visited = {}
    for i = 1, rows do visited[i] = {}; for j = 1, cols do visited[i][j] = false end end
    local count = 0
    local function dfs(r, c)
        if r<1 or r>rows or c<1 or c>cols or visited[r][c] or grid[r][c]==0 then return end
        visited[r][c] = true; dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1)
    end
    for r = 1, rows do for c = 1, cols do
        if not visited[r][c] and grid[r][c] == 1 then count=count+1; dfs(r,c) end
    end end
    return count
end

function M.problem84()
    print("Problem 84:")
    local g = {{1,0,0,0,0},{0,0,1,1,0},{0,1,1,0,0},{0,0,0,0,0},{1,1,0,0,1},{1,1,0,0,1}}
    assert(M.count_islands(g) == 4)
    print("All Tests Passed")
end

return M
