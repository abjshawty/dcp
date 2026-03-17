use rand::Rng;

fn toss_biased() -> u8 { if rand::thread_rng().gen::<f64>() < 0.7 { 1 } else { 0 } }

pub fn unbiased_coin() -> u8 {
    loop {
        let (a, b) = (toss_biased(), toss_biased());
        if a == 0 && b == 1 { return 0; }
        if a == 1 && b == 0 { return 1; }
    }
}

pub fn problem66() {
    println!("Problem 66:");
    let mut counts = [0u32; 2];
    for _ in 0..10000 { counts[unbiased_coin() as usize] += 1; }
    assert!(counts[0] > 4000 && counts[1] > 4000);
    println!("All Tests Passed");
}
