local M = {}

local function merge_sort(arr)
    if #arr <= 1 then return arr, 0 end
    local mid = math.floor(#arr / 2)
    local left, lc = merge_sort({table.unpack(arr, 1, mid)})
    local right, rc = merge_sort({table.unpack(arr, mid + 1)})
    local merged, mc = {}, 0
    local i, j = 1, 1
    while i <= #left and j <= #right do
        if left[i] <= right[j] then
            merged[#merged+1] = left[i]; i = i + 1
        else
            merged[#merged+1] = right[j]; mc = mc + (#left - i + 1); j = j + 1
        end
    end
    while i <= #left do merged[#merged+1] = left[i]; i = i + 1 end
    while j <= #right do merged[#merged+1] = right[j]; j = j + 1 end
    return merged, lc + rc + mc
end

function M.count_inversions(arr)
    local _, count = merge_sort(arr)
    return count
end

function M.problem44()
    print("Problem 44:")
    assert(M.count_inversions({2,4,1,3,5}) == 3)
    assert(M.count_inversions({5,4,3,2,1}) == 10)
    assert(M.count_inversions({1,2,3})     == 0)
    print("All Tests Passed")
end

return M
