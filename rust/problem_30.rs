pub fn trap_water(heights: &[i64]) -> i64 {
    if heights.is_empty() { return 0; }
    let (mut left, mut right) = (0usize, heights.len() - 1);
    let (mut left_max, mut right_max, mut water) = (0i64, 0i64, 0i64);
    while left < right {
        if heights[left] < heights[right] {
            if heights[left] >= left_max { left_max = heights[left]; }
            else { water += left_max - heights[left]; }
            left += 1;
        } else {
            if heights[right] >= right_max { right_max = heights[right]; }
            else { water += right_max - heights[right]; }
            right -= 1;
        }
    }
    water
}

pub fn problem30() {
    println!("Problem 30:");
    assert_eq!(trap_water(&[2,1,2]),                            1);
    assert_eq!(trap_water(&[3,0,1,3,0,5]),                      8);
    assert_eq!(trap_water(&[0,1,0,2,1,0,1,3,2,1,2,1]),          6);
    assert_eq!(trap_water(&[]),                                  0);
    println!("All Tests Passed");
}
