class SLNode26 {
    constructor(public val: number, public next: SLNode26 | null = null) {}
}

function slList26(...vals: number[]): SLNode26 | null {
    const dummy = new SLNode26(0);
    let cur: SLNode26 = dummy;
    for (const v of vals) { cur.next = new SLNode26(v); cur = cur.next; }
    return dummy.next;
}

function slToArray26(head: SLNode26 | null): number[] {
    const out: number[] = [];
    while (head) { out.push(head.val); head = head.next; }
    return out;
}

function removeKthLast(head: SLNode26 | null, k: number): SLNode26 | null {
    const dummy = new SLNode26(0, head);
    let fast: SLNode26 | null = dummy;
    let slow: SLNode26 | null = dummy;
    for (let i = 0; i <= k; i++) fast = fast!.next;
    while (fast) { fast = fast.next; slow = slow!.next; }
    slow!.next = slow!.next!.next;
    return dummy.next;
}

export function problem26(): void {
    console.log("Problem 26:");
    const r1 = slToArray26(removeKthLast(slList26(1,2,3,4,5), 2));
    if (JSON.stringify(r1) !== JSON.stringify([1,2,3,5])) throw new Error("assertion failed");
    const r2 = slToArray26(removeKthLast(slList26(1,2,3), 1));
    if (JSON.stringify(r2) !== JSON.stringify([1,2]))     throw new Error("assertion failed");
    const r3 = slToArray26(removeKthLast(slList26(1,2), 2));
    if (JSON.stringify(r3) !== JSON.stringify([2]))       throw new Error("assertion failed");
    console.log("All Tests Passed");
}
