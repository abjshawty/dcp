local function sortRGB(arr)
    local lo, mid, hi = 1, 1, #arr
    while mid <= hi do
        if arr[mid] == 'R' then
            arr[lo], arr[mid] = arr[mid], arr[lo]
            lo = lo + 1; mid = mid + 1
        elseif arr[mid] == 'G' then
            mid = mid + 1
        else
            arr[mid], arr[hi] = arr[hi], arr[mid]
            hi = hi - 1
        end
    end
end

local function tableEq(a, b)
    if #a ~= #b then return false end
    for i = 1, #a do if a[i] ~= b[i] then return false end end
    return true
end

local function problem35()
    print("Problem 35:")
    local arr = {'G','B','R','R','B','R','G'}
    sortRGB(arr)
    assert(tableEq(arr, {'R','R','R','G','G','B','B'}), "assertion failed")
    local arr2 = {'B','G','R'}
    sortRGB(arr2)
    assert(tableEq(arr2, {'R','G','B'}), "assertion failed")
    print("All Tests Passed")
end

return { problem35 = problem35 }
