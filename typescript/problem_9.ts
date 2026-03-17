// largestSumNonAdjacent returns the largest sum of non-adjacent elements.
// Uses O(1) space DP: at each step, either skip (keep prev) or take
// (prevPrev + current). This runs in O(n) time.
export function largestSumNonAdjacent(nums: number[]): number {
    let prevPrev = 0, prev = 0;
    for (const n of nums) {
        const curr = Math.max(prev, prevPrev + n); // skip or take
        prevPrev = prev;
        prev = curr;
    }
    return prev;
}

export function problem9(): void {
    console.log("Problem 9:");
    if (largestSumNonAdjacent([2, 4, 6, 2, 5]) !== 13) throw new Error("assertion failed");
    if (largestSumNonAdjacent([5, 1, 1, 5])    !== 10) throw new Error("assertion failed");
    if (largestSumNonAdjacent([])               !== 0)  throw new Error("assertion failed");
    if (largestSumNonAdjacent([3])              !== 3)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
