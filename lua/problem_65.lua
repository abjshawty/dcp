local M = {}

function M.spiral_order(matrix)
    local top, bottom = 1, #matrix
    local left, right = 1, #matrix[1]
    local result = {}
    while top <= bottom and left <= right do
        for c = left, right do result[#result+1] = matrix[top][c] end; top = top + 1
        for r = top, bottom do result[#result+1] = matrix[r][right] end; right = right - 1
        if top <= bottom then
            for c = right, left, -1 do result[#result+1] = matrix[bottom][c] end; bottom = bottom - 1
        end
        if left <= right then
            for r = bottom, top, -1 do result[#result+1] = matrix[r][left] end; left = left + 1
        end
    end
    return result
end

function M.problem65()
    print("Problem 65:")
    local m = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}}
    local exp = {1,2,3,4,5,10,15,20,19,18,17,16,11,6,7,8,9,14,13,12}
    local got = M.spiral_order(m)
    assert(#got == #exp)
    for i = 1, #exp do assert(got[i] == exp[i]) end
    print("All Tests Passed")
end

return M
