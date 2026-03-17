// staircase returns the number of unique ways to climb n steps
// when you can take any step size from the steps set.
// Uses bottom-up DP. This runs in O(n * |steps|) time and O(n) space.
export function staircase(n: number, steps: number[]): number {
    const ways = new Array<number>(n + 1).fill(0);
    ways[0] = 1; // one way to stand at the bottom
    for (let i = 1; i <= n; i++)
        for (const s of steps)
            if (i - s >= 0) ways[i] += ways[i - s];
    return ways[n];
}

export function problem12(): void {
    console.log("Problem 12:");
    if (staircase(4, [1, 2])    !== 5) throw new Error("assertion failed");
    if (staircase(4, [1, 3, 5]) !== 3) throw new Error("assertion failed");
    if (staircase(0, [1, 2])    !== 1) throw new Error("assertion failed");
    if (staircase(1, [1, 2])    !== 1) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
