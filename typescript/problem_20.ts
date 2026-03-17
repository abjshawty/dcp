// ListNode is a singly linked list node.
export class ListNode {
    constructor(public val: number, public next: ListNode | null = null) {}
}

// intersectingNode finds the first shared node of two linked lists.
// Advances two pointers; when one reaches the end it restarts at the
// other list's head. They meet at the intersection after M+N steps.
// This runs in O(M+N) time and O(1) space.
export function intersectingNode(headA: ListNode | null, headB: ListNode | null): ListNode | null {
    let a = headA, b = headB;
    while (a !== b) {
        a = a === null ? headB : a.next;
        b = b === null ? headA : b.next;
    }
    return a;
}

export function problem20(): void {
    console.log("Problem 20:");
    const shared = new ListNode(8, new ListNode(10));
    const headA = new ListNode(3, new ListNode(7, shared));
    const headB = new ListNode(99, new ListNode(1, shared));
    if (intersectingNode(headA, headB) !== shared) throw new Error("assertion failed");
    if (intersectingNode(new ListNode(1), new ListNode(2)) !== null) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
