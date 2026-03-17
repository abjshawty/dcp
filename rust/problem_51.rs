use rand::Rng;

pub fn shuffle(deck: &mut Vec<i32>) {
    let mut rng = rand::thread_rng();
    for i in (1..deck.len()).rev() {
        let j = rng.gen_range(0..=i);
        deck.swap(i, j);
    }
}

pub fn problem51() {
    println!("Problem 51:");
    let mut deck: Vec<i32> = (0..52).collect();
    shuffle(&mut deck);
    let mut sorted = deck.clone();
    sorted.sort();
    let expected: Vec<i32> = (0..52).collect();
    assert_eq!(sorted, expected);
    println!("All Tests Passed");
}
