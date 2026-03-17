pub fn count_islands(grid: &Vec<Vec<u8>>) -> usize {
    let rows = grid.len(); let cols = grid[0].len();
    let mut visited = vec![vec![false; cols]; rows];
    let mut count = 0;
    fn dfs(r: i64, c: i64, rows: usize, cols: usize, grid: &Vec<Vec<u8>>, visited: &mut Vec<Vec<bool>>) {
        if r<0||r>=rows as i64||c<0||c>=cols as i64 { return; }
        let (r,c)=(r as usize,c as usize);
        if visited[r][c] || grid[r][c]==0 { return; }
        visited[r][c]=true;
        dfs(r as i64+1,c as i64,rows,cols,grid,visited); dfs(r as i64-1,c as i64,rows,cols,grid,visited);
        dfs(r as i64,c as i64+1,rows,cols,grid,visited); dfs(r as i64,c as i64-1,rows,cols,grid,visited);
    }
    for r in 0..rows { for c in 0..cols {
        if !visited[r][c] && grid[r][c]==1 { count+=1; dfs(r as i64,c as i64,rows,cols,grid,&mut visited); }
    } }
    count
}

pub fn problem84() {
    println!("Problem 84:");
    let g = vec![vec![1,0,0,0,0],vec![0,0,1,1,0],vec![0,1,1,0,0],vec![0,0,0,0,0],vec![1,1,0,0,1],vec![1,1,0,0,1]];
    assert_eq!(count_islands(&g), 4);
    println!("All Tests Passed");
}
