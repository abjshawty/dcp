from typing import List, Tuple, Optional


Board = List[List[int]]


def solve_sudoku(board: Board) -> Optional[Board]:
    for r in range(9):
        for c in range(9):
            if board[r][c] != 0:
                continue
            for d in range(1, 10):
                if _valid(board, r, c, d):
                    board[r][c] = d
                    if solve_sudoku(board):
                        return board
                    board[r][c] = 0
            return None
    return board


def _valid(board: Board, r: int, c: int, d: int) -> bool:
    if d in board[r]: return False
    if d in [board[i][c] for i in range(9)]: return False
    br, bc = (r // 3) * 3, (c // 3) * 3
    for i in range(3):
        for j in range(3):
            if board[br+i][bc+j] == d: return False
    return True


def main():
    print("Problem 54:")
    board = [
        [5,3,0,0,7,0,0,0,0],
        [6,0,0,1,9,5,0,0,0],
        [0,9,8,0,0,0,0,6,0],
        [8,0,0,0,6,0,0,0,3],
        [4,0,0,8,0,3,0,0,1],
        [7,0,0,0,2,0,0,0,6],
        [0,6,0,0,0,0,2,8,0],
        [0,0,0,4,1,9,0,0,5],
        [0,0,0,0,8,0,0,7,9],
    ]
    solved = solve_sudoku(board)
    assert solved is not None
    assert all(solved[r][c] != 0 for r in range(9) for c in range(9))
    print("All Tests Passed")
