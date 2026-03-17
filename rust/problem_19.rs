// min_cost_paint returns the minimum cost to paint N houses with K colors
// such that no two adjacent houses share the same color.
// Uses bottom-up DP. This runs in O(N*K) time.
pub fn min_cost_paint(costs: &[Vec<i64>]) -> i64 {
    if costs.is_empty() { return 0; }
    let n = costs.len();
    let k = costs[0].len();
    let mut dp: Vec<Vec<i64>> = costs.to_vec();

    for i in 1..n {
        for c in 0..k {
            let min_prev = (0..k).filter(|&p| p != c).map(|p| dp[i-1][p]).min().unwrap();
            dp[i][c] += min_prev;
        }
    }
    *dp[n-1].iter().min().unwrap()
}

pub fn problem19() {
    println!("Problem 19:");
    let costs = vec![vec![17,2,17], vec![16,16,5], vec![14,3,19]];
    assert_eq!(min_cost_paint(&costs),                10, "assertion failed");
    assert_eq!(min_cost_paint(&[vec![1,2,3]]),         1, "assertion failed");
    println!("All Tests Passed");
}
