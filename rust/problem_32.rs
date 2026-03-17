pub fn has_arbitrage(rates: &[Vec<f64>]) -> bool {
    let n = rates.len();
    let mut dist = vec![0.0f64; n];
    for _ in 0..n-1 {
        for i in 0..n {
            for j in 0..n {
                if rates[i][j] == 0.0 { continue; }
                let w = -rates[i][j].ln();
                if dist[i] + w < dist[j] { dist[j] = dist[i] + w; }
            }
        }
    }
    for i in 0..n {
        for j in 0..n {
            if rates[i][j] == 0.0 { continue; }
            let w = -rates[i][j].ln();
            if dist[i] + w < dist[j] { return true; }
        }
    }
    false
}

pub fn problem32() {
    println!("Problem 32:");
    let arb  = vec![vec![1.0,0.9,0.8],vec![1.2,1.0,0.9],vec![1.4,1.2,1.0]];
    let fair = vec![vec![1.0,2.0,4.0],vec![0.5,1.0,2.0],vec![0.25,0.5,1.0]];
    assert!( has_arbitrage(&arb));
    assert!(!has_arbitrage(&fair));
    println!("All Tests Passed");
}
