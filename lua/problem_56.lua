local M = {}

function M.graph_colorable(adj, k)
    local n = #adj
    local colors = {}
    for i = 1, n do colors[i] = 0 end
    local function bt(node)
        if node > n then return true end
        for c = 1, k do
            local ok = true
            for nb = 1, n do
                if adj[node][nb] == 1 and colors[nb] == c then ok = false; break end
            end
            if ok then
                colors[node] = c
                if bt(node + 1) then return true end
                colors[node] = 0
            end
        end
        return false
    end
    return bt(1)
end

function M.problem56()
    print("Problem 56:")
    local t = {{0,1,1},{1,0,1},{1,1,0}}
    assert(    M.graph_colorable(t, 3))
    assert(not M.graph_colorable(t, 2))
    print("All Tests Passed")
end

return M
