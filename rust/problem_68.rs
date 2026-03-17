use std::collections::HashMap;

pub fn count_bishop_pairs(bishops: &[(i64,i64)], m: i64) -> i64 {
    let mut d1: HashMap<i64,i64> = HashMap::new();
    let mut d2: HashMap<i64,i64> = HashMap::new();
    for &(r,c) in bishops {
        *d1.entry(r - c + m).or_insert(0) += 1;
        *d2.entry(r + c).or_insert(0) += 1;
    }
    let pairs = |map: &HashMap<i64,i64>| map.values().map(|&v| v*(v-1)/2).sum::<i64>();
    pairs(&d1) + pairs(&d2)
}

pub fn problem68() {
    println!("Problem 68:");
    assert_eq!(count_bishop_pairs(&[(0,0),(1,2),(2,2),(4,0)], 5), 2);
    println!("All Tests Passed");
}
