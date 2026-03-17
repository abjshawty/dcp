class BSTNode36 {
    constructor(public val: number, public left: BSTNode36 | null = null, public right: BSTNode36 | null = null) {}
}

export function secondLargest(root: BSTNode36): number {
    let parent: BSTNode36 | null = null;
    let curr: BSTNode36 = root;
    while (curr.right) { parent = curr; curr = curr.right; }
    if (curr.left) {
        let node = curr.left;
        while (node.right) node = node.right;
        return node.val;
    }
    return parent!.val;
}

export function problem36(): void {
    console.log("Problem 36:");
    const root = new BSTNode36(5,
        new BSTNode36(3, new BSTNode36(2), new BSTNode36(4)),
        new BSTNode36(7, new BSTNode36(6), new BSTNode36(8))
    );
    if (secondLargest(root) !== 7) throw new Error("assertion failed");
    const root2 = new BSTNode36(3, null, new BSTNode36(4, null, new BSTNode36(5)));
    if (secondLargest(root2) !== 4) throw new Error("assertion failed");
    const root3 = new BSTNode36(5, new BSTNode36(3, null, new BSTNode36(4)), null);
    if (secondLargest(root3) !== 4) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
