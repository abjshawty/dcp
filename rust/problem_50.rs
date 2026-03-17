pub enum ExprNode50 {
    Leaf(f64),
    Op(char, Box<ExprNode50>, Box<ExprNode50>),
}

pub fn eval_expr(node: &ExprNode50) -> f64 {
    match node {
        ExprNode50::Leaf(v) => *v,
        ExprNode50::Op(op, l, r) => {
            let lv = eval_expr(l); let rv = eval_expr(r);
            match op { '+' => lv+rv, '-' => lv-rv, '*' => lv*rv, _ => lv/rv }
        }
    }
}

pub fn problem50() {
    println!("Problem 50:");
    use ExprNode50::*;
    let root = Op('*',
        Box::new(Op('+', Box::new(Leaf(3.0)), Box::new(Leaf(2.0)))),
        Box::new(Op('+', Box::new(Leaf(4.0)), Box::new(Leaf(5.0)))),
    );
    assert_eq!(eval_expr(&root), 45.0);
    println!("All Tests Passed");
}
