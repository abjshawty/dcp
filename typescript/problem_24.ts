class LockNode {
    val: number;
    locked: boolean = false;
    lockedDescCount: number = 0;
    parent: LockNode | null;
    left: LockNode | null = null;
    right: LockNode | null = null;

    constructor(val: number, parent: LockNode | null = null) {
        this.val = val;
        this.parent = parent;
    }

    isLocked(): boolean { return this.locked; }

    private canLockOrUnlock(): boolean {
        if (this.lockedDescCount > 0) return false;
        let p = this.parent;
        while (p) {
            if (p.locked) return false;
            p = p.parent;
        }
        return true;
    }

    lock(): boolean {
        if (this.locked || !this.canLockOrUnlock()) return false;
        this.locked = true;
        let p = this.parent;
        while (p) { p.lockedDescCount++; p = p.parent; }
        return true;
    }

    unlock(): boolean {
        if (!this.locked || !this.canLockOrUnlock()) return false;
        this.locked = false;
        let p = this.parent;
        while (p) { p.lockedDescCount--; p = p.parent; }
        return true;
    }
}

export function problem24(): void {
    console.log("Problem 24:");
    const root = new LockNode(1);
    root.left  = new LockNode(2, root);
    root.right = new LockNode(3, root);
    root.left.left = new LockNode(4, root.left);

    if (!root.left.lock())           throw new Error("assertion failed");
    if (!root.left.isLocked())       throw new Error("assertion failed");
    if (root.lock())                 throw new Error("assertion failed"); // locked descendant
    if (root.left.left.lock())       throw new Error("assertion failed"); // ancestor locked
    if (!root.left.unlock())         throw new Error("assertion failed");
    if (root.left.isLocked())        throw new Error("assertion failed");
    if (!root.lock())                throw new Error("assertion failed");
    console.log("All Tests Passed");
}
