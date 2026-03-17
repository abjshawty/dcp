use std::collections::{HashMap, HashSet};

pub fn game_of_life_step(alive: &HashSet<(i32, i32)>) -> HashSet<(i32, i32)> {
    let mut counts: HashMap<(i32, i32), usize> = HashMap::new();
    for &(r, c) in alive {
        for dr in -1..=1 {
            for dc in -1..=1 {
                if dr == 0 && dc == 0 { continue; }
                *counts.entry((r + dr, c + dc)).or_insert(0) += 1;
            }
        }
    }
    let mut next = HashSet::new();
    for (&p, &cnt) in &counts {
        if alive.contains(&p) && (cnt == 2 || cnt == 3) { next.insert(p); }
        if !alive.contains(&p) && cnt == 3              { next.insert(p); }
    }
    next
}

pub fn problem39() {
    println!("Problem 39:");
    let blinker: HashSet<(i32,i32)> = [(0,0),(0,1),(0,2)].iter().cloned().collect();
    let s1 = game_of_life_step(&blinker);
    assert_eq!(s1.len(), 3);
    let s2 = game_of_life_step(&s1);
    assert_eq!(s2.len(), 3);
    assert!(s2.contains(&(0,0)) && s2.contains(&(0,1)) && s2.contains(&(0,2)));
    println!("All Tests Passed");
}
