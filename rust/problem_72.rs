pub fn largest_value_path(labels: &str, edges: &[(usize,usize)]) -> Option<usize> {
    let n = labels.len();
    let chars: Vec<u8> = labels.bytes().collect();
    let mut adj: Vec<Vec<usize>> = vec![vec![]; n];
    let mut indegree = vec![0usize; n];
    for &(u,v) in edges {
        if u == v { return None; }
        adj[u].push(v); indegree[v] += 1;
    }
    let mut dp = vec![[0usize; 26]; n];
    let mut queue: std::collections::VecDeque<usize> = (0..n).filter(|&i| indegree[i]==0).collect();
    let (mut visited, mut best) = (0, 0);
    while let Some(node) = queue.pop_front() {
        visited += 1;
        let c = (chars[node] - b'A') as usize;
        dp[node][c] += 1;
        best = best.max(*dp[node].iter().max().unwrap());
        for &nb in &adj[node].clone() {
            for k in 0..26 { dp[nb][k] = dp[nb][k].max(dp[node][k]); }
            indegree[nb] -= 1;
            if indegree[nb] == 0 { queue.push_back(nb); }
        }
    }
    if visited != n { None } else { Some(best) }
}

pub fn problem72() {
    println!("Problem 72:");
    assert_eq!(largest_value_path("ABACA", &[(0,1),(0,2),(2,3),(3,4)]), Some(3));
    assert_eq!(largest_value_path("A", &[(0,0)]), None);
    println!("All Tests Passed");
}
