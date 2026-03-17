// shortestPath returns the minimum steps from start to end in a boolean grid
// where true = wall. Uses BFS for guaranteed shortest path.
// Returns -1 if no path exists. This runs in O(M*N) time and space.
export function shortestPath(
    grid: boolean[][],
    startR: number, startC: number,
    endR: number,   endC: number,
): number {
    const rows = grid.length, cols = grid[0].length;
    if (grid[startR][startC] || grid[endR][endC]) return -1;

    const visited = Array.from({ length: rows }, () => new Array<boolean>(cols).fill(false));
    visited[startR][startC] = true;
    let queue: [number, number][] = [[startR, startC]];
    let steps = 0;
    const dirs: [number, number][] = [[-1,0],[1,0],[0,-1],[0,1]];

    while (queue.length > 0) {
        const next: [number, number][] = [];
        for (const [r, c] of queue) {
            if (r === endR && c === endC) return steps;
            for (const [dr, dc] of dirs) {
                const nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !grid[nr][nc] && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    next.push([nr, nc]);
                }
            }
        }
        queue = next;
        steps++;
    }
    return -1;
}

export function problem23(): void {
    console.log("Problem 23:");
    const f = false, t = true;
    const grid = [[f,f,f,f],[t,t,f,t],[f,f,f,f],[f,f,f,f]];
    if (shortestPath(grid, 3,0, 0,0) !== 7)  throw new Error("assertion failed");
    if (shortestPath(grid, 0,0, 0,0) !== 0)  throw new Error("assertion failed");
    if (shortestPath([[f,t],[t,f]], 0,0, 1,1) !== -1) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
