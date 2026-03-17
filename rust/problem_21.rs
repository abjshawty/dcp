// min_rooms returns the minimum number of rooms to schedule all intervals.
// Sort by start time; use a sorted Vec as a min-heap substitute for end times.
// This runs in O(n log n) time.
pub fn min_rooms(intervals: &[(i64, i64)]) -> usize {
    if intervals.is_empty() { return 0; }
    let mut sorted = intervals.to_vec();
    sorted.sort_by_key(|&(s, _)| s);
    let mut ends: Vec<i64> = Vec::new(); // kept sorted (ascending)

    for (start, end) in sorted {
        if !ends.is_empty() && ends[0] <= start {
            ends.remove(0); // reuse earliest-ending room
        }
        let pos = ends.partition_point(|&e| e <= end);
        ends.insert(pos, end);
    }
    ends.len()
}

pub fn problem21() {
    println!("Problem 21:");
    assert_eq!(min_rooms(&[(30,75),(0,50),(60,150)]), 2, "assertion failed");
    assert_eq!(min_rooms(&[(0,10),(10,20)]),           1, "assertion failed");
    assert_eq!(min_rooms(&[(0,10),(0,10)]),            2, "assertion failed");
    println!("All Tests Passed");
}
