export class MaxStack {
    private data: number[] = [];
    private maxs: number[] = [];

    push(val: number): void {
        this.data.push(val);
        this.maxs.push(this.maxs.length === 0 ? val : Math.max(val, this.maxs[this.maxs.length - 1]));
    }

    pop(): number | null {
        if (this.data.length === 0) return null;
        this.maxs.pop();
        return this.data.pop()!;
    }

    max(): number | null {
        return this.maxs.length === 0 ? null : this.maxs[this.maxs.length - 1];
    }
}

export function problem43(): void {
    console.log("Problem 43:");
    const s = new MaxStack();
    s.push(1); s.push(3); s.push(2);
    if (s.max() !== 3) throw new Error("assertion failed");
    if (s.pop() !== 2) throw new Error("assertion failed");
    if (s.max() !== 3) throw new Error("assertion failed");
    if (s.pop() !== 3) throw new Error("assertion failed");
    if (s.max() !== 1) throw new Error("assertion failed");
    if (new MaxStack().pop() !== null) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
