local M = {}

function M.random_excluding(n, exclude)
    local excl = {}
    for _, v in ipairs(exclude) do excl[v] = true end
    local valid = {}
    for i = 0, n - 1 do
        if not excl[i] then valid[#valid+1] = i end
    end
    return valid[math.random(1, #valid)]
end

function M.problem90()
    print("Problem 90:")
    for _ = 1, 100 do
        assert(M.random_excluding(5, {0,1,2,4}) == 3)
    end
    local counts = {}
    for _ = 1, 1000 do
        local v = M.random_excluding(5, {2})
        counts[v] = (counts[v] or 0) + 1
    end
    for _, k in ipairs({0,1,3,4}) do
        assert((counts[k] or 0) > 100, "bad distribution")
    end
    print("All Tests Passed")
end

return M
