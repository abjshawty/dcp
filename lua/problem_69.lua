local M = {}

function M.largest_product_of_three(nums)
    table.sort(nums)
    local n = #nums
    local opt1 = nums[n] * nums[n-1] * nums[n-2]
    local opt2 = nums[1] * nums[2] * nums[n]
    return math.max(opt1, opt2)
end

function M.problem69()
    print("Problem 69:")
    assert(M.largest_product_of_three({-10,-10,5,2})   == 500)
    assert(M.largest_product_of_three({1,2,3})          == 6)
    assert(M.largest_product_of_three({-5,-4,-3,-2,-1}) == -6)
    print("All Tests Passed")
end

return M
