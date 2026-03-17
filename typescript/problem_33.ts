export function runningMedian(nums: number[]): number[] {
    const result: number[] = [];
    const sorted: number[] = [];
    for (const v of nums) {
        let lo = 0, hi = sorted.length;
        while (lo < hi) { const mid = (lo + hi) >> 1; sorted[mid] < v ? lo = mid + 1 : hi = mid; }
        sorted.splice(lo, 0, v);
        const n = sorted.length;
        result.push(n % 2 === 1 ? sorted[n >> 1] : (sorted[(n >> 1) - 1] + sorted[n >> 1]) / 2);
    }
    return result;
}

export function problem33(): void {
    console.log("Problem 33:");
    const got = runningMedian([2,1,5,7,2,0,5]);
    const exp = [2, 1.5, 2, 3.5, 2, 2, 2];
    if (JSON.stringify(got) !== JSON.stringify(exp)) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
