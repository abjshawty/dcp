class TreeNode80ts { constructor(public val:string, public left:TreeNode80ts|null=null, public right:TreeNode80ts|null=null){} }

export function deepestNode(root: TreeNode80ts|null): [string, number] {
    if (!root) return ['', 0];
    const [lv,ld] = deepestNode(root.left), [rv,rd] = deepestNode(root.right);
    if (ld > rd) return [lv, ld+1];
    if (rd > ld) return [rv, rd+1];
    return [root.val, 1];
}

export function problem80(): void {
    console.log("Problem 80:");
    const root = new TreeNode80ts('a', new TreeNode80ts('b', new TreeNode80ts('d')), new TreeNode80ts('c'));
    if (deepestNode(root)[0] !== 'd') throw new Error("assertion failed");
    console.log("All Tests Passed");
}
