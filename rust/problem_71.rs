use rand::Rng;

fn rand7_71() -> u32 { rand::thread_rng().gen_range(1..=7) }

pub fn rand5_71() -> u32 { loop { let v = rand7_71(); if v <= 5 { return v; } } }

pub fn problem71() {
    println!("Problem 71:");
    let mut counts = [0u32; 6];
    for _ in 0..50000 { let v = rand5_71() as usize; assert!(v>=1&&v<=5); counts[v]+=1; }
    for i in 1..=5 { assert!(counts[i]>7000&&counts[i]<13000); }
    println!("All Tests Passed");
}
