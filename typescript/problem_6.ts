// XorLinkedList is an XOR doubly-linked list backed by an array.
// Array indices serve as stand-in memory addresses.
interface XorNodeEntry { val: number; both: number; }

export class XorLinkedList {
    private nodes: XorNodeEntry[] = [];
    private head = -1;
    private tail = -1;

    // add appends an element to the end of the list.
    add(val: number): void {
        const idx = this.nodes.length;
        const prev = this.tail;
        this.nodes.push({ val, both: prev ^ -1 }); // both = prev XOR null(-1)
        if (this.tail !== -1) {
            // update old tail: replace null(-1) with new index
            this.nodes[this.tail].both ^= (-1 ^ idx);
        }
        this.tail = idx;
        if (this.head === -1) this.head = idx;
    }

    // get returns the value at the given 0-based index.
    get(index: number): number {
        let prev = -1, curr = this.head;
        for (let i = 0; i < index; i++) {
            const next = prev ^ this.nodes[curr].both; // XOR out prev to get next
            prev = curr;
            curr = next;
        }
        return this.nodes[curr].val;
    }
}

export function problem6(): void {
    console.log("Problem 6:");
    const lst = new XorLinkedList();
    for (const v of [1, 2, 3, 4]) lst.add(v);
    if (lst.get(0) !== 1) throw new Error("assertion failed");
    if (lst.get(1) !== 2) throw new Error("assertion failed");
    if (lst.get(2) !== 3) throw new Error("assertion failed");
    if (lst.get(3) !== 4) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
