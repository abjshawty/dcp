use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

// schedule calls f after n milliseconds in a background thread.
pub fn schedule<F: FnOnce() + Send + 'static>(f: F, n: u64) {
    thread::spawn(move || {
        thread::sleep(Duration::from_millis(n));
        f();
    });
}

pub fn problem10() {
    println!("Problem 10:");
    let fired = Arc::new(Mutex::new(false));
    let fired_clone = Arc::clone(&fired);
    schedule(move || { *fired_clone.lock().unwrap() = true; }, 50);
    thread::sleep(Duration::from_millis(200)); // wait for the callback
    assert!(*fired.lock().unwrap(), "assertion failed");
    println!("All Tests Passed");
}
