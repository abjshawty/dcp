def knight_tours(n: int) -> int:
    board = [[False] * n for _ in range(n)]
    moves = [(2,1),(2,-1),(-2,1),(-2,-1),(1,2),(1,-2),(-1,2),(-1,-2)]
    count = [0]

    def dfs(r: int, c: int, visited: int):
        if visited == n * n:
            count[0] += 1
            return
        for dr, dc in moves:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n and not board[nr][nc]:
                board[nr][nc] = True
                dfs(nr, nc, visited + 1)
                board[nr][nc] = False

    for r in range(n):
        for c in range(n):
            board[r][c] = True
            dfs(r, c, 1)
            board[r][c] = False
    return count[0]


def main():
    print("Problem 64:")
    assert knight_tours(1) == 1
    assert knight_tours(2) == 0
    assert knight_tours(3) == 0
    print("All Tests Passed")
