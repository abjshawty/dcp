local function trapWater(heights)
    if #heights == 0 then return 0 end
    local left, right = 1, #heights
    local leftMax, rightMax, water = 0, 0, 0
    while left < right do
        if heights[left] < heights[right] then
            if heights[left] >= leftMax then
                leftMax = heights[left]
            else
                water = water + leftMax - heights[left]
            end
            left = left + 1
        else
            if heights[right] >= rightMax then
                rightMax = heights[right]
            else
                water = water + rightMax - heights[right]
            end
            right = right - 1
        end
    end
    return water
end

local function problem30()
    print("Problem 30:")
    assert(trapWater({2,1,2})                             == 1, "assertion failed")
    assert(trapWater({3,0,1,3,0,5})                       == 8, "assertion failed")
    assert(trapWater({0,1,0,2,1,0,1,3,2,1,2,1})           == 6, "assertion failed")
    assert(trapWater({})                                   == 0, "assertion failed")
    print("All Tests Passed")
end

return { problem30 = problem30 }
