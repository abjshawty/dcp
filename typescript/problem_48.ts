class TreeNode48ts {
    constructor(public val: string, public left: TreeNode48ts | null = null, public right: TreeNode48ts | null = null) {}
}

export function buildTree(preorder: string[], inorder: string[]): TreeNode48ts | null {
    if (!preorder.length) return null;
    const root = new TreeNode48ts(preorder[0]);
    const idx = inorder.indexOf(preorder[0]);
    root.left  = buildTree(preorder.slice(1, 1 + idx), inorder.slice(0, idx));
    root.right = buildTree(preorder.slice(1 + idx), inorder.slice(idx + 1));
    return root;
}

function inorderTs(root: TreeNode48ts | null): string[] {
    if (!root) return [];
    return [...inorderTs(root.left), root.val, ...inorderTs(root.right)];
}

export function problem48(): void {
    console.log("Problem 48:");
    const pre = ["a","b","d","e","c","f","g"];
    const ino = ["d","b","e","a","f","c","g"];
    if (JSON.stringify(inorderTs(buildTree(pre, ino))) !== JSON.stringify(ino))
        throw new Error("assertion failed");
    console.log("All Tests Passed");
}
