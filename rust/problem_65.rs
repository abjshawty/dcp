pub fn spiral_order(matrix: &Vec<Vec<i32>>) -> Vec<i32> {
    let (mut top, mut bottom) = (0i64, matrix.len() as i64 - 1);
    let (mut left, mut right) = (0i64, matrix[0].len() as i64 - 1);
    let mut result = vec![];
    while top <= bottom && left <= right {
        for c in left..=right { result.push(matrix[top as usize][c as usize]); } top += 1;
        for r in top..=bottom { result.push(matrix[r as usize][right as usize]); } right -= 1;
        if top <= bottom { for c in (left..=right).rev() { result.push(matrix[bottom as usize][c as usize]); } bottom -= 1; }
        if left <= right { for r in (top..=bottom).rev() { result.push(matrix[r as usize][left as usize]); } left += 1; }
    }
    result
}

pub fn problem65() {
    println!("Problem 65:");
    let m = vec![vec![1,2,3,4,5],vec![6,7,8,9,10],vec![11,12,13,14,15],vec![16,17,18,19,20]];
    let exp = vec![1,2,3,4,5,10,15,20,19,18,17,16,11,6,7,8,9,14,13,12];
    assert_eq!(spiral_order(&m), exp);
    println!("All Tests Passed");
}
