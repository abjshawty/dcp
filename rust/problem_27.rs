pub fn is_balanced(s: &str) -> bool {
    let mut stack: Vec<char> = Vec::new();
    for c in s.chars() {
        match c {
            '(' | '[' | '{' => stack.push(c),
            ')' => { if stack.pop() != Some('(') { return false; } }
            ']' => { if stack.pop() != Some('[') { return false; } }
            '}' => { if stack.pop() != Some('{') { return false; } }
            _ => {}
        }
    }
    stack.is_empty()
}

pub fn problem27() {
    println!("Problem 27:");
    assert!( is_balanced("([])[]({})" ));
    assert!(!is_balanced("([)]")       );
    assert!(!is_balanced("(((()")      );
    assert!( is_balanced("")           );
    assert!( is_balanced("{[]}")       );
    println!("All Tests Passed");
}
