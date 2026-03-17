// cons constructs a pair encoded as a closure. car and cdr extract the first
// and second elements by passing selector functions into the pair.
pub fn cons(a: i64, b: i64) -> impl Fn(fn(i64, i64) -> i64) -> i64 {
    move |f| f(a, b)
}

// car returns the first element of a pair.
pub fn car(pair: impl Fn(fn(i64, i64) -> i64) -> i64) -> i64 {
    pair(|a, _| a)
}

// cdr returns the second element of a pair.
pub fn cdr(pair: impl Fn(fn(i64, i64) -> i64) -> i64) -> i64 {
    pair(|_, b| b)
}

pub fn problem5() {
    println!("Problem 5:");
    assert_eq!(car(cons(3, 4)),   3,  "assertion failed");
    assert_eq!(cdr(cons(3, 4)),   4,  "assertion failed");
    assert_eq!(car(cons(0, -1)),  0,  "assertion failed");
    assert_eq!(cdr(cons(0, -1)), -1,  "assertion failed");
    println!("All Tests Passed");
}
