// reservoirSample picks one element uniformly at random from a stream.
// Keeps the first element, then for each subsequent element i replaces
// with probability 1/(i+1). This runs in O(n) time and O(1) space.
export function reservoirSample(stream: number[], seed = 42): number {
    let s = seed;
    const rand = (n: number) => { s = (s * 1664525 + 1013904223) & 0xffffffff; return (s >>> 0) % n; };
    let result = stream[0];
    for (let i = 1; i < stream.length; i++)
        if (rand(i + 1) === 0) result = stream[i];
    return result;
}

export function problem15(): void {
    console.log("Problem 15:");
    const stream = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const counts = new Map<number, number>();
    const trials = 100_000;
    for (let seed = 0; seed < trials; seed++) {
        const v = reservoirSample(stream, seed);
        counts.set(v, (counts.get(v) ?? 0) + 1);
    }
    for (const v of stream) {
        const freq = (counts.get(v) ?? 0) / trials;
        if (freq < 0.08 || freq > 0.12)
            throw new Error(`assertion failed: element ${v} frequency ${freq}`);
    }
    console.log("All Tests Passed");
}
