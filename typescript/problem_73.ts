class ListNode73ts {
    constructor(public val: number, public next: ListNode73ts | null = null) {}
}

export function reverseList(head: ListNode73ts | null): ListNode73ts | null {
    let prev: ListNode73ts | null = null, curr = head;
    while (curr) { const nxt = curr.next; curr.next = prev; prev = curr; curr = nxt; }
    return prev;
}

function fromList73(vals: number[]): ListNode73ts | null {
    const d = new ListNode73ts(0); let c = d;
    for (const v of vals) { c.next = new ListNode73ts(v); c = c.next; }
    return d.next;
}
function toList73(h: ListNode73ts | null): number[] {
    const r: number[] = []; while(h){r.push(h.val);h=h.next;} return r;
}

export function problem73(): void {
    console.log("Problem 73:");
    if (JSON.stringify(toList73(reverseList(fromList73([1,2,3,4,5])))) !== JSON.stringify([5,4,3,2,1]))
        throw new Error("assertion failed");
    if (reverseList(null) !== null) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
