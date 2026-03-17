-- shortestPath returns the minimum steps from start to end in a boolean grid
-- where true = wall. Uses BFS for guaranteed shortest path.
-- Returns -1 if no path exists. This runs in O(M*N) time and space.
-- Coordinates are 1-based {row, col} tables.
local function shortestPath(grid, startR, startC, endR, endC)
    local rows = #grid
    local cols = #grid[1]
    if grid[startR][startC] or grid[endR][endC] then return -1 end

    local visited = {}
    for r = 1, rows do
        visited[r] = {}
        for c = 1, cols do visited[r][c] = false end
    end
    visited[startR][startC] = true

    local queue = { {startR, startC} }
    local steps = 0
    local dirs = { {-1,0},{1,0},{0,-1},{0,1} }

    while #queue > 0 do
        local next = {}
        for _, p in ipairs(queue) do
            local r, c = p[1], p[2]
            if r == endR and c == endC then return steps end
            for _, d in ipairs(dirs) do
                local nr, nc = r + d[1], c + d[2]
                if nr >= 1 and nr <= rows and nc >= 1 and nc <= cols
                   and not grid[nr][nc] and not visited[nr][nc] then
                    visited[nr][nc] = true
                    next[#next+1] = {nr, nc}
                end
            end
        end
        queue = next
        steps = steps + 1
    end
    return -1
end

local function problem23()
    print("Problem 23:")
    local f, t = false, true
    local grid = {
        {f,f,f,f},
        {t,t,f,t},
        {f,f,f,f},
        {f,f,f,f},
    }
    -- coordinates are 1-based; (3,0) in 0-based = (4,1) in 1-based
    assert(shortestPath(grid, 4,1, 1,1) == 7, "assertion failed")
    assert(shortestPath(grid, 1,1, 1,1) == 0, "assertion failed")
    local blocked = {{f,t},{t,f}}
    assert(shortestPath(blocked, 1,1, 2,2) == -1, "assertion failed")
    print("All Tests Passed")
end

return { problem23 = problem23 }
