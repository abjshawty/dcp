local M = {}

function M.max_subarray_sum(arr)
    local best, cur = 0, 0
    for _, v in ipairs(arr) do
        cur = math.max(0, cur + v)
        best = math.max(best, cur)
    end
    return best
end

function M.problem49()
    print("Problem 49:")
    assert(M.max_subarray_sum({34,-50,42,14,-5,86}) == 137)
    assert(M.max_subarray_sum({-5,-1,-8,-9})         == 0)
    assert(M.max_subarray_sum({1,2,3})               == 6)
    print("All Tests Passed")
end

return M
