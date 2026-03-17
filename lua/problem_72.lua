local M = {}

function M.largest_value_path(labels, edges)
    local n = #labels
    local adj = {}; for i = 1, n do adj[i] = {} end
    local indegree = {}; for i = 1, n do indegree[i] = 0 end
    for _, e in ipairs(edges) do
        if e[1] == e[2] then return nil end
        adj[e[1]][#adj[e[1]]+1] = e[2]
        indegree[e[2]] = indegree[e[2]] + 1
    end
    local dp = {}
    for i = 1, n do dp[i] = {}; for c = 0, 25 do dp[i][c] = 0 end end
    local queue = {}
    for i = 1, n do if indegree[i] == 0 then queue[#queue+1] = i end end
    local visited, best = 0, 0
    local qi = 1
    while qi <= #queue do
        local node = queue[qi]; qi = qi + 1
        visited = visited + 1
        local c = string.byte(labels, node) - string.byte('A')
        dp[node][c] = dp[node][c] + 1
        for cc = 0, 25 do if dp[node][cc] > best then best = dp[node][cc] end end
        for _, nb in ipairs(adj[node]) do
            for cc = 0, 25 do
                if dp[node][cc] > dp[nb][cc] then dp[nb][cc] = dp[node][cc] end
            end
            indegree[nb] = indegree[nb] - 1
            if indegree[nb] == 0 then queue[#queue+1] = nb end
        end
    end
    if visited ~= n then return nil end
    return best
end

function M.problem72()
    print("Problem 72:")
    assert(M.largest_value_path("ABACA", {{1,2},{1,3},{3,4},{4,5}}) == 3)
    assert(M.largest_value_path("A", {{1,1}}) == nil)
    print("All Tests Passed")
end

return M
