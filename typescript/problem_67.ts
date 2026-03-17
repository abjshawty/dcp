export class LFUCache67 {
    private cap: number;
    private keys = new Map<number, {val: number; freq: number}>();
    private freqs = new Map<number, Map<number, null>>();
    private minFreq = 0;
    constructor(cap: number) { this.cap = cap; }
    private touch(key: number): void {
        const e = this.keys.get(key)!;
        this.freqs.get(e.freq)!.delete(key);
        if (!this.freqs.get(e.freq)!.size) { this.freqs.delete(e.freq); if (this.minFreq === e.freq) this.minFreq++; }
        e.freq++;
        if (!this.freqs.has(e.freq)) this.freqs.set(e.freq, new Map());
        this.freqs.get(e.freq)!.set(key, null);
    }
    get(key: number): number | null {
        if (!this.keys.has(key)) return null;
        this.touch(key); return this.keys.get(key)!.val;
    }
    set(key: number, val: number): void {
        if (!this.cap) return;
        if (this.keys.has(key)) { this.keys.get(key)!.val = val; this.touch(key); return; }
        if (this.keys.size === this.cap) {
            const evict = this.freqs.get(this.minFreq)!.keys().next().value as number;
            this.freqs.get(this.minFreq)!.delete(evict); this.keys.delete(evict);
        }
        this.keys.set(key, {val, freq: 1});
        if (!this.freqs.has(1)) this.freqs.set(1, new Map());
        this.freqs.get(1)!.set(key, null); this.minFreq = 1;
    }
}

export function problem67(): void {
    console.log("Problem 67:");
    const c = new LFUCache67(2);
    c.set(1,1); c.set(2,2);
    if (c.get(1) !== 1) throw new Error("assertion failed");
    c.set(3,3);
    if (c.get(2) !== null) throw new Error("2 should be evicted");
    if (c.get(3) !== 3)   throw new Error("assertion failed");
    console.log("All Tests Passed");
}
