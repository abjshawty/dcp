from collections import deque


def shortest_path(grid: list[list[bool]], start: tuple[int,int], end: tuple[int,int]) -> int | None:
    # shortest_path returns the minimum steps from start to end in a boolean
    # grid where True = wall. Uses BFS for guaranteed shortest path.
    # Returns None if no path exists.
    # This runs in O(M*N) time and space.
    rows, cols = len(grid), len(grid[0])
    sr, sc = start
    er, ec = end
    if grid[sr][sc] or grid[er][ec]:
        return None

    visited = [[False] * cols for _ in range(rows)]
    visited[sr][sc] = True
    queue: deque[tuple[int,int,int]] = deque([(sr, sc, 0)])

    for r, c, steps in queue:
        if r == er and c == ec:
            return steps
        for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and not grid[nr][nc] and not visited[nr][nc]:
                visited[nr][nc] = True
                queue.append((nr, nc, steps + 1))

    return None  # no path found


def main():
    print("Problem 23:")
    f, t = False, True
    grid = [
        [f, f, f, f],
        [t, t, f, t],
        [f, f, f, f],
        [f, f, f, f],
    ]
    assert shortest_path(grid, (3, 0), (0, 0)) == 7,    "assertion failed"
    assert shortest_path(grid, (0, 0), (0, 0)) == 0,    "assertion failed"
    assert shortest_path([[f, t],[t, f]], (0,0), (1,1)) is None, "assertion failed"
    print("All Tests Passed")
