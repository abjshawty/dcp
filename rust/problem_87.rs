use std::collections::HashMap;

pub fn validate_rules(rules: &[&str]) -> bool {
    let mut x_lo: HashMap<&str,f64> = HashMap::new();
    let mut x_hi: HashMap<&str,f64> = HashMap::new();
    let mut y_lo: HashMap<&str,f64> = HashMap::new();
    let mut y_hi: HashMap<&str,f64> = HashMap::new();
    let mx = |m: &mut HashMap<&str,f64>, k: &'static str, v: f64| { let e = m.entry(k).or_insert(f64::NEG_INFINITY); if v > *e { *e = v; } };
    let mn = |m: &mut HashMap<&str,f64>, k: &'static str, v: f64| { let e = m.entry(k).or_insert(f64::INFINITY); if v < *e { *e = v; } };
    let check = |xl: &HashMap<&str,f64>, xh: &HashMap<&str,f64>, yl: &HashMap<&str,f64>, yh: &HashMap<&str,f64>| -> bool {
        for (k, &lo) in xl { if lo >= *xh.get(k).unwrap_or(&f64::INFINITY) { return false; } }
        for (k, &lo) in yl { if lo >= *yh.get(k).unwrap_or(&f64::INFINITY) { return false; } }
        true
    };
    for rule in rules {
        let parts: Vec<&str> = rule.split_whitespace().collect();
        if parts.len() != 3 { continue; }
        let (a, dir, b) = (parts[0], parts[1], parts[2]);
        let eps = 1.0f64;
        let yb = *y_lo.get(b).unwrap_or(&0.0); let yt = *y_hi.get(b).unwrap_or(&0.0);
        let xb = *x_lo.get(b).unwrap_or(&0.0); let xt = *x_hi.get(b).unwrap_or(&0.0);
        match dir {
            "N"  => { let v=yb+eps; *y_lo.entry(a).or_insert(f64::NEG_INFINITY) = v.max(*y_lo.get(a).unwrap_or(&f64::NEG_INFINITY)); }
            "S"  => { let v=yt-eps; *y_hi.entry(a).or_insert(f64::INFINITY)     = v.min(*y_hi.get(a).unwrap_or(&f64::INFINITY)); }
            "E"  => { let v=xb+eps; *x_lo.entry(a).or_insert(f64::NEG_INFINITY) = v.max(*x_lo.get(a).unwrap_or(&f64::NEG_INFINITY)); }
            "W"  => { let v=xt-eps; *x_hi.entry(a).or_insert(f64::INFINITY)     = v.min(*x_hi.get(a).unwrap_or(&f64::INFINITY)); }
            "NE" => {
                let vy=yb+eps; *y_lo.entry(a).or_insert(f64::NEG_INFINITY) = vy.max(*y_lo.get(a).unwrap_or(&f64::NEG_INFINITY));
                let vx=xb+eps; *x_lo.entry(a).or_insert(f64::NEG_INFINITY) = vx.max(*x_lo.get(a).unwrap_or(&f64::NEG_INFINITY));
            }
            "NW" => {
                let vy=yb+eps; *y_lo.entry(a).or_insert(f64::NEG_INFINITY) = vy.max(*y_lo.get(a).unwrap_or(&f64::NEG_INFINITY));
                let vx=xt-eps; *x_hi.entry(a).or_insert(f64::INFINITY)     = vx.min(*x_hi.get(a).unwrap_or(&f64::INFINITY));
            }
            "SE" => {
                let vy=yt-eps; *y_hi.entry(a).or_insert(f64::INFINITY)     = vy.min(*y_hi.get(a).unwrap_or(&f64::INFINITY));
                let vx=xb+eps; *x_lo.entry(a).or_insert(f64::NEG_INFINITY) = vx.max(*x_lo.get(a).unwrap_or(&f64::NEG_INFINITY));
            }
            "SW" => {
                let vy=yt-eps; *y_hi.entry(a).or_insert(f64::INFINITY)     = vy.min(*y_hi.get(a).unwrap_or(&f64::INFINITY));
                let vx=xt-eps; *x_hi.entry(a).or_insert(f64::INFINITY)     = vx.min(*x_hi.get(a).unwrap_or(&f64::INFINITY));
            }
            _ => {}
        }
        if !check(&x_lo, &x_hi, &y_lo, &y_hi) { return false; }
    }
    true
}

pub fn problem87() {
    println!("Problem 87:");
    assert!( validate_rules(&["A N B","B NE C","C N A"]) == false);
    assert!( validate_rules(&["A NW B","A N B"]));
    println!("All Tests Passed");
}
