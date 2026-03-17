// estimate_pi estimates π using Monte Carlo simulation.
// Uses a simple LCG for reproducibility.
pub fn estimate_pi(samples: u64, seed: u64) -> f64 {
    let mut s = seed;
    let lcg = |state: &mut u64| -> f64 {
        *state = state.wrapping_mul(6364136223846793005).wrapping_add(1442695040888963407);
        (*state >> 33) as f64 / (u64::MAX >> 33) as f64
    };
    let inside = (0..samples).filter(|_| {
        let x = lcg(&mut s);
        let y = lcg(&mut s);
        x * x + y * y <= 1.0
    }).count();
    4.0 * inside as f64 / samples as f64
}

pub fn problem14() {
    println!("Problem 14:");
    let pi = estimate_pi(1_000_000, 42);
    assert!((pi - std::f64::consts::PI).abs() < 0.01,
        "assertion failed: got {}", pi);
    println!("All Tests Passed");
}
