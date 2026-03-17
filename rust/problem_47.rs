pub fn max_profit(prices: &[i64]) -> i64 {
    if prices.len() < 2 { return 0; }
    let mut min_price = prices[0];
    let mut best = 0;
    for &p in &prices[1..] {
        best = best.max(p - min_price);
        min_price = min_price.min(p);
    }
    best
}

pub fn problem47() {
    println!("Problem 47:");
    assert_eq!(max_profit(&[9,11,8,5,7,10]), 5);
    assert_eq!(max_profit(&[1,2,3,4,5]),     4);
    assert_eq!(max_profit(&[5,4,3,2,1]),     0);
    println!("All Tests Passed");
}
