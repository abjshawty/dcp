local M = {}

function M.min_columns_to_remove(rows)
    if #rows == 0 then return 0 end
    local cols = #rows[1]
    local remove = 0
    for c = 1, cols do
        for r = 2, #rows do
            if rows[r]:sub(c,c) < rows[r-1]:sub(c,c) then
                remove = remove + 1; break
            end
        end
    end
    return remove
end

function M.problem76()
    print("Problem 76:")
    assert(M.min_columns_to_remove({"cba","daf","ghi"}) == 1)
    assert(M.min_columns_to_remove({"abcdef"})           == 0)
    assert(M.min_columns_to_remove({"zyx","wvu","tsr"}) == 3)
    print("All Tests Passed")
end

return M
