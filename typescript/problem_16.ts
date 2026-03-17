// OrderLog records the last N order IDs using a circular buffer.
// record and getLast both run in O(1) time and O(N) space.
export class OrderLog {
    private buf: number[];
    private pos = 0;

    constructor(private n: number) {
        this.buf = new Array<number>(n).fill(0);
    }

    record(orderId: number): void {
        this.buf[this.pos] = orderId;
        this.pos = (this.pos + 1) % this.n;
    }

    getLast(i: number): number {
        return this.buf[(this.pos - i + this.n) % this.n];
    }
}

export function problem16(): void {
    console.log("Problem 16:");
    const log = new OrderLog(3);
    log.record(1); log.record(2); log.record(3);
    if (log.getLast(1) !== 3) throw new Error("assertion failed");
    if (log.getLast(2) !== 2) throw new Error("assertion failed");
    if (log.getLast(3) !== 1) throw new Error("assertion failed");
    log.record(4);
    if (log.getLast(1) !== 4) throw new Error("assertion failed");
    if (log.getLast(2) !== 3) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
