export function maxSubarraySum(arr: number[]): number {
    let best = 0, cur = 0;
    for (const v of arr) {
        cur = Math.max(0, cur + v);
        best = Math.max(best, cur);
    }
    return best;
}

export function problem49(): void {
    console.log("Problem 49:");
    if (maxSubarraySum([34,-50,42,14,-5,86]) !== 137) throw new Error("assertion failed");
    if (maxSubarraySum([-5,-1,-8,-9])        !== 0)   throw new Error("assertion failed");
    if (maxSubarraySum([1,2,3])              !== 6)   throw new Error("assertion failed");
    console.log("All Tests Passed");
}
