export function largestProductOfThree(nums: number[]): number {
    nums.sort((a,b)=>a-b);
    const n = nums.length;
    return Math.max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
}

export function problem69(): void {
    console.log("Problem 69:");
    if (largestProductOfThree([-10,-10,5,2])     !== 500) throw new Error("assertion failed");
    if (largestProductOfThree([1,2,3])            !== 6)   throw new Error("assertion failed");
    if (largestProductOfThree([-5,-4,-3,-2,-1])   !== -6)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
