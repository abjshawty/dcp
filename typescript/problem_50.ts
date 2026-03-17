class ExprNode50 {
    constructor(public val: string, public left: ExprNode50 | null = null, public right: ExprNode50 | null = null) {}
}

export function evalExpr(root: ExprNode50): number {
    if (!root.left && !root.right) return parseFloat(root.val);
    const l = evalExpr(root.left!), r = evalExpr(root.right!);
    switch (root.val) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        default:  return l / r;
    }
}

export function problem50(): void {
    console.log("Problem 50:");
    const root = new ExprNode50('*',
        new ExprNode50('+', new ExprNode50('3'), new ExprNode50('2')),
        new ExprNode50('+', new ExprNode50('4'), new ExprNode50('5')),
    );
    if (evalExpr(root) !== 45) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
