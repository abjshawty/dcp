export function countBishopPairs(bishops: [number,number][], m: number): number {
    const d1 = new Map<number,number>(), d2 = new Map<number,number>();
    for (const [r,c] of bishops) {
        d1.set(r-c+m, (d1.get(r-c+m)??0)+1);
        d2.set(r+c,   (d2.get(r+c)??0)+1);
    }
    let count = 0;
    for (const v of d1.values()) count += v*(v-1)/2;
    for (const v of d2.values()) count += v*(v-1)/2;
    return count;
}

export function problem68(): void {
    console.log("Problem 68:");
    if (countBishopPairs([[0,0],[1,2],[2,2],[4,0]], 5) !== 2) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
