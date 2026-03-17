// Node is a binary tree node with a string value and left/right children.
export class Node {
    constructor(
        public val: string,
        public left: Node | null = null,
        public right: Node | null = null,
    ) {}
}

// serialize encodes a binary tree into a comma-separated string using
// pre-order traversal. Null nodes are represented with the sentinel "#".
export function serialize(root: Node | null): string {
    if (root === null)
        return "#";
    // pre-order: root, left subtree, right subtree
    return `${root.val},${serialize(root.left)},${serialize(root.right)}`;
}

// deserialize reconstructs a binary tree from a string produced by serialize.
// It consumes tokens from a shared iterator, mirroring the pre-order encoding.
export function deserialize(s: string): Node | null {
    const tokens = s.split(",");
    let idx = 0;

    function build(): Node | null {
        const val = tokens[idx++];
        if (val === "#") // sentinel marks a null node
            return null;
        // reconstruct pre-order: node first, then left and right subtrees
        return new Node(val, build(), build());
    }

    return build();
}

export function problem3(): void {
    console.log("Problem 3:");
    const node = new Node("root",
        new Node("left", new Node("left.left")),
        new Node("right"));
    const result = deserialize(serialize(node));
    if (result?.left?.left?.val !== "left.left") throw new Error("assertion failed");
    console.log("All Tests Passed");
}
