// IntNode is a binary tree node with an integer value.
export class IntNode {
    constructor(
        public val: number,
        public left: IntNode | null = null,
        public right: IntNode | null = null,
    ) {}
}

// countUnivalSubtrees counts subtrees where every node has the same value.
// A leaf is always unival. An internal node is unival if both children are
// unival and share the node's value. Uses post-order DFS.
function helper(node: IntNode | null): [boolean, number] {
    if (node === null) return [true, 0]; // null is trivially unival
    const [leftUnival,  leftCount]  = helper(node.left);
    const [rightUnival, rightCount] = helper(node.right);
    let count = leftCount + rightCount;

    const isUnival =
        leftUnival && rightUnival &&
        (node.left  === null || node.left.val  === node.val) &&
        (node.right === null || node.right.val === node.val);

    if (isUnival) count++;
    return [isUnival, count];
}

export function countUnivalSubtrees(root: IntNode | null): number {
    return helper(root)[1];
}

export function problem8(): void {
    console.log("Problem 8:");
    //       0
    //      / \
    //     1   0
    //        / \
    //       1   0
    //      / \
    //     1   1
    const root = new IntNode(0,
        new IntNode(1),
        new IntNode(0,
            new IntNode(1, new IntNode(1), new IntNode(1)),
            new IntNode(0),
        ),
    );
    if (countUnivalSubtrees(root) !== 5) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
