export class StackQueue {
    private inbox: number[] = [];
    private outbox: number[] = [];
    enqueue(val: number): void { this.inbox.push(val); }
    dequeue(): number | null {
        if (!this.outbox.length) while (this.inbox.length) this.outbox.push(this.inbox.pop()!);
        return this.outbox.length ? this.outbox.pop()! : null;
    }
}

export function problem53(): void {
    console.log("Problem 53:");
    const q = new StackQueue();
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    if (q.dequeue() !== 1) throw new Error("assertion failed");
    if (q.dequeue() !== 2) throw new Error("assertion failed");
    q.enqueue(4);
    if (q.dequeue() !== 3) throw new Error("assertion failed");
    if (q.dequeue() !== 4) throw new Error("assertion failed");
    if (q.dequeue() !== null) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
