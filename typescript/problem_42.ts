export function subsetSum(nums: number[], target: number): number[] | null {
    function bt(idx: number, remaining: number, current: number[]): number[] | null {
        if (remaining === 0) return [...current];
        if (idx === nums.length || remaining < 0) return null;
        current.push(nums[idx]);
        const r = bt(idx + 1, remaining - nums[idx], current);
        if (r !== null) return r;
        current.pop();
        return bt(idx + 1, remaining, current);
    }
    return bt(0, target, []);
}

export function problem42(): void {
    console.log("Problem 42:");
    const r1 = subsetSum([12,1,61,5,9,2], 24);
    if (r1 === null || r1.reduce((a,b)=>a+b,0) !== 24) throw new Error("assertion failed");
    if (subsetSum([1,2,3], 100) !== null) throw new Error("assertion failed");
    const r3 = subsetSum([5], 5);
    if (JSON.stringify(r3) !== JSON.stringify([5])) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
