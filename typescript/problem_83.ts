class TreeNode83ts { constructor(public val:number, public left:TreeNode83ts|null=null, public right:TreeNode83ts|null=null){} }

export function invertTree(root: TreeNode83ts|null): TreeNode83ts|null {
    if (!root) return null;
    [root.left, root.right] = [invertTree(root.right), invertTree(root.left)];
    return root;
}

function inorder83ts(root: TreeNode83ts|null): number[] {
    if (!root) return [];
    return [...inorder83ts(root.left), root.val, ...inorder83ts(root.right)];
}

export function problem83(): void {
    console.log("Problem 83:");
    const root = new TreeNode83ts(4,
        new TreeNode83ts(2, new TreeNode83ts(1), new TreeNode83ts(3)),
        new TreeNode83ts(7, new TreeNode83ts(6), new TreeNode83ts(9))
    );
    if (JSON.stringify(inorder83ts(invertTree(root))) !== JSON.stringify([9,7,6,4,3,2,1]))
        throw new Error("assertion failed");
    console.log("All Tests Passed");
}
