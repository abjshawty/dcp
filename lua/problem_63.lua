local M = {}

function M.word_in_matrix(matrix, word)
    local rows = #matrix
    local cols = #matrix[1]
    local n = #word
    for r = 1, rows do
        for c = 1, cols - n + 1 do
            local match = true
            for i = 1, n do
                if matrix[r][c+i-1] ~= word:sub(i,i) then match = false; break end
            end
            if match then return true end
        end
    end
    for c = 1, cols do
        for r = 1, rows - n + 1 do
            local match = true
            for i = 1, n do
                if matrix[r+i-1][c] ~= word:sub(i,i) then match = false; break end
            end
            if match then return true end
        end
    end
    return false
end

function M.problem63()
    print("Problem 63:")
    local m = {{'F','A','C','I'},{'O','B','Q','P'},{'A','N','O','B'},{'M','A','S','S'}}
    assert(    M.word_in_matrix(m, "FOAM"))
    assert(    M.word_in_matrix(m, "MASS"))
    assert(not M.word_in_matrix(m, "NOPE"))
    print("All Tests Passed")
end

return M
