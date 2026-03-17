local M = {}

function M.search_rotated(arr, target)
    local lo, hi = 1, #arr
    while lo <= hi do
        local mid = math.floor((lo + hi) / 2)
        if arr[mid] == target then return mid end
        if arr[lo] <= arr[mid] then
            if arr[lo] <= target and target < arr[mid] then hi = mid - 1
            else lo = mid + 1 end
        else
            if arr[mid] < target and target <= arr[hi] then lo = mid + 1
            else hi = mid - 1 end
        end
    end
    return nil
end

function M.problem58()
    print("Problem 58:")
    assert(M.search_rotated({13,18,25,2,8,10}, 8)  == 5)
    assert(M.search_rotated({13,18,25,2,8,10}, 13) == 1)
    assert(M.search_rotated({13,18,25,2,8,10}, 99) == nil)
    print("All Tests Passed")
end

return M
