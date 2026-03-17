use rand::Rng;

fn rand5() -> u32 { rand::thread_rng().gen_range(1..=5) }

pub fn rand7() -> u32 {
    loop {
        let n = (rand5() - 1) * 5 + (rand5() - 1);
        if n < 21 { return n % 7 + 1; }
    }
}

pub fn problem45() {
    println!("Problem 45:");
    let mut counts = [0u32; 8];
    for _ in 0..70000 {
        let v = rand7() as usize;
        assert!(v >= 1 && v <= 7);
        counts[v] += 1;
    }
    for i in 1..=7 { assert!(counts[i] > 7000 && counts[i] < 13000, "bad distribution"); }
    println!("All Tests Passed");
}
