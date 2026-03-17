local M = {}

local function valid(board, r, c, d)
    for i = 1, 9 do
        if board[r][i] == d or board[i][c] == d then return false end
    end
    local br = math.floor((r-1)/3)*3+1
    local bc = math.floor((c-1)/3)*3+1
    for i = 0, 2 do for j = 0, 2 do
        if board[br+i][bc+j] == d then return false end
    end end
    return true
end

local function solve(board)
    for r = 1, 9 do for c = 1, 9 do
        if board[r][c] == 0 then
            for d = 1, 9 do
                if valid(board, r, c, d) then
                    board[r][c] = d
                    if solve(board) then return true end
                    board[r][c] = 0
                end
            end
            return false
        end
    end end
    return true
end

function M.solve_sudoku(board) solve(board); return board end

function M.problem54()
    print("Problem 54:")
    local board = {
        {5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9},
    }
    M.solve_sudoku(board)
    for r = 1, 9 do for c = 1, 9 do assert(board[r][c] ~= 0) end end
    print("All Tests Passed")
end

return M
