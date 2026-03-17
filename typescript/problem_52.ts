export class LRUCache52 {
    private cap: number;
    private cache: Map<number, number>;
    constructor(cap: number) { this.cap = cap; this.cache = new Map(); }
    get(key: number): number | null {
        if (!this.cache.has(key)) return null;
        const v = this.cache.get(key)!;
        this.cache.delete(key); this.cache.set(key, v);
        return v;
    }
    set(key: number, val: number): void {
        if (this.cache.has(key)) this.cache.delete(key);
        this.cache.set(key, val);
        if (this.cache.size > this.cap) this.cache.delete(this.cache.keys().next().value!);
    }
}

export function problem52(): void {
    console.log("Problem 52:");
    const c = new LRUCache52(2);
    c.set(1,1); c.set(2,2);
    if (c.get(1) !== 1) throw new Error("assertion failed");
    c.set(3,3);
    if (c.get(2) !== null) throw new Error("2 should be evicted");
    if (c.get(3) !== 3)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
