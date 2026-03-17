export function canPartition(nums: number[]): boolean {
    const total = nums.reduce((a, b) => a + b, 0);
    if (total % 2 !== 0) return false;
    const target = total / 2;
    const dp = new Array(target + 1).fill(false);
    dp[0] = true;
    for (const v of nums)
        for (let j = target; j >= v; j--)
            dp[j] = dp[j] || dp[j - v];
    return dp[target];
}

export function problem60(): void {
    console.log("Problem 60:");
    if (!canPartition([15,5,20,10,35,15,10])) throw new Error("assertion failed");
    if ( canPartition([15,5,20,10,35]))       throw new Error("assertion failed");
    if (!canPartition([1,5,11,5]))            throw new Error("assertion failed");
    console.log("All Tests Passed");
}
