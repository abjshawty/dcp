class TreeNode89ts { constructor(public val:number, public left:TreeNode89ts|null=null, public right:TreeNode89ts|null=null){} }

export function isValidBST(root: TreeNode89ts|null, lo=-Infinity, hi=Infinity): boolean {
    if (!root) return true;
    if (root.val <= lo || root.val >= hi) return false;
    return isValidBST(root.left, lo, root.val) && isValidBST(root.right, root.val, hi);
}

export function problem89(): void {
    console.log("Problem 89:");
    const valid = new TreeNode89ts(5,
        new TreeNode89ts(3, new TreeNode89ts(2), new TreeNode89ts(4)),
        new TreeNode89ts(7, new TreeNode89ts(6), new TreeNode89ts(8))
    );
    const invalid = new TreeNode89ts(5, new TreeNode89ts(3), new TreeNode89ts(4));
    if (!isValidBST(valid))   throw new Error("assertion failed");
    if ( isValidBST(invalid)) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
