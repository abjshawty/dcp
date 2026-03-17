local M = {}

function M.merge_intervals(intervals)
    table.sort(intervals, function(a,b) return a[1] < b[1] end)
    local result = {{intervals[1][1], intervals[1][2]}}
    for i = 2, #intervals do
        local s, e = intervals[i][1], intervals[i][2]
        local last = result[#result]
        if s <= last[2] then
            if e > last[2] then last[2] = e end
        else
            result[#result+1] = {s, e}
        end
    end
    return result
end

function M.problem77()
    print("Problem 77:")
    local got = M.merge_intervals({{1,3},{5,8},{4,10},{20,25}})
    local exp = {{1,3},{4,10},{20,25}}
    assert(#got == #exp)
    for i = 1, #exp do assert(got[i][1]==exp[i][1] and got[i][2]==exp[i][2]) end
    print("All Tests Passed")
end

return M
