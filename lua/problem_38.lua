local function nQueens(n)
    local cols  = {}
    local diag1 = {}
    local diag2 = {}
    local count = 0
    local function place(row)
        if row > n then count = count + 1; return end
        for col = 1, n do
            local d1 = row - col
            local d2 = row + col
            if not cols[col] and not diag1[d1] and not diag2[d2] then
                cols[col] = true; diag1[d1] = true; diag2[d2] = true
                place(row + 1)
                cols[col] = nil; diag1[d1] = nil; diag2[d2] = nil
            end
        end
    end
    place(1)
    return count
end

local function problem38()
    print("Problem 38:")
    assert(nQueens(1) == 1,  "assertion failed")
    assert(nQueens(4) == 2,  "assertion failed")
    assert(nQueens(8) == 92, "assertion failed")
    print("All Tests Passed")
end

return { problem38 = problem38 }
