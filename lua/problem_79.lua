local M = {}

function M.can_be_non_decreasing(nums)
    local a = {table.unpack(nums)}
    local modified = false
    for i = 2, #a do
        if a[i] < a[i-1] then
            if modified then return false end
            modified = true
            if i >= 3 and a[i] < a[i-2] then a[i] = a[i-1]
            else a[i-1] = a[i] end
        end
    end
    return true
end

function M.problem79()
    print("Problem 79:")
    assert(    M.can_be_non_decreasing({10,5,7}))
    assert(not M.can_be_non_decreasing({10,5,1}))
    assert(    M.can_be_non_decreasing({1,2,3}))
    print("All Tests Passed")
end

return M
