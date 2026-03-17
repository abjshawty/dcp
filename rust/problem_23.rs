use std::collections::VecDeque;

// shortest_path returns the minimum steps from start to end in a boolean grid
// where true = wall. Uses BFS. Returns None if no path exists.
// This runs in O(M*N) time and space.
pub fn shortest_path(
    grid: &[Vec<bool>],
    start: (usize, usize),
    end: (usize, usize),
) -> Option<usize> {
    let rows = grid.len();
    let cols = grid[0].len();
    if grid[start.0][start.1] || grid[end.0][end.1] { return None; }

    let mut visited = vec![vec![false; cols]; rows];
    visited[start.0][start.1] = true;
    let mut queue: VecDeque<(usize, usize, usize)> = VecDeque::new();
    queue.push_back((start.0, start.1, 0));

    while let Some((r, c, steps)) = queue.pop_front() {
        if (r, c) == end { return Some(steps); }
        for (dr, dc) in [(-1i32,0),(1,0),(0,-1i32),(0,1)] {
            let nr = r as i32 + dr;
            let nc = c as i32 + dc;
            if nr >= 0 && nr < rows as i32 && nc >= 0 && nc < cols as i32 {
                let (nr, nc) = (nr as usize, nc as usize);
                if !grid[nr][nc] && !visited[nr][nc] {
                    visited[nr][nc] = true;
                    queue.push_back((nr, nc, steps + 1));
                }
            }
        }
    }
    None
}

pub fn problem23() {
    println!("Problem 23:");
    let f = false; let t = true;
    let grid = vec![
        vec![f,f,f,f],
        vec![t,t,f,t],
        vec![f,f,f,f],
        vec![f,f,f,f],
    ];
    assert_eq!(shortest_path(&grid, (3,0), (0,0)), Some(7), "assertion failed");
    assert_eq!(shortest_path(&grid, (0,0), (0,0)), Some(0), "assertion failed");
    let blocked = vec![vec![f,t],vec![t,f]];
    assert_eq!(shortest_path(&blocked, (0,0), (1,1)), None, "assertion failed");
    println!("All Tests Passed");
}
