pub fn merge_intervals(mut intervals: Vec<(i64,i64)>) -> Vec<(i64,i64)> {
    intervals.sort();
    let mut result = vec![intervals[0]];
    for (s,e) in &intervals[1..] {
        let last = result.last_mut().unwrap();
        if *s <= last.1 { if *e > last.1 { last.1 = *e; } }
        else { result.push((*s, *e)); }
    }
    result
}

pub fn problem77() {
    println!("Problem 77:");
    let got = merge_intervals(vec![(1,3),(5,8),(4,10),(20,25)]);
    assert_eq!(got, vec![(1,3),(4,10),(20,25)]);
    println!("All Tests Passed");
}
