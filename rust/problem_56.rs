pub fn graph_colorable(adj: &Vec<Vec<i32>>, k: usize) -> bool {
    let n = adj.len();
    let mut colors = vec![0usize; n];
    fn bt(node: usize, n: usize, adj: &Vec<Vec<i32>>, k: usize, colors: &mut Vec<usize>) -> bool {
        if node == n { return true; }
        for c in 1..=k {
            if (0..n).all(|nb| adj[node][nb] == 0 || colors[nb] != c) {
                colors[node] = c;
                if bt(node+1, n, adj, k, colors) { return true; }
                colors[node] = 0;
            }
        }
        false
    }
    bt(0, n, adj, k, &mut colors)
}

pub fn problem56() {
    println!("Problem 56:");
    let t = vec![vec![0,1,1],vec![1,0,1],vec![1,1,0]];
    assert!( graph_colorable(&t, 3));
    assert!(!graph_colorable(&t, 2));
    println!("All Tests Passed");
}
