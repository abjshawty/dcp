// staircase returns the number of unique ways to climb n steps
// when you can take any step size from steps.
// Uses bottom-up DP. This runs in O(n * |steps|) time and O(n) space.
pub fn staircase(n: usize, steps: &[usize]) -> usize {
    let mut ways = vec![0usize; n + 1];
    ways[0] = 1; // one way to stand at the bottom
    for i in 1..=n {
        for &s in steps {
            if i >= s { ways[i] += ways[i - s]; }
        }
    }
    ways[n]
}

pub fn problem12() {
    println!("Problem 12:");
    assert_eq!(staircase(4, &[1, 2]),    5, "assertion failed");
    assert_eq!(staircase(4, &[1, 3, 5]), 3, "assertion failed");
    assert_eq!(staircase(0, &[1, 2]),    1, "assertion failed");
    assert_eq!(staircase(1, &[1, 2]),    1, "assertion failed");
    println!("All Tests Passed");
}
