local function singleNumber(nums)
    local result = 0
    for bit = 0, 31 do
        local total = 0
        for _, n in ipairs(nums) do
            total = total + (math.floor(n / 2^bit) % 2)
        end
        if total % 3 ~= 0 then result = result + 2^bit end
    end
    return result
end

local function problem40()
    print("Problem 40:")
    assert(singleNumber({6,1,3,3,3,6,6}) == 1,  "assertion failed")
    assert(singleNumber({13,19,13,13})   == 19, "assertion failed")
    assert(singleNumber({0,0,0,5})       == 5,  "assertion failed")
    print("All Tests Passed")
end

return { problem40 = problem40 }
