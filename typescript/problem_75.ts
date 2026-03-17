export function longestIncreasingSubsequence(nums: number[]): number {
    const tails: number[] = [];
    for (const v of nums) {
        let lo=0, hi=tails.length;
        while(lo<hi){const mid=(lo+hi)>>1; tails[mid]<v?lo=mid+1:hi=mid;}
        tails[lo]=v; if(lo===tails.length-1&&lo===tails.length-1&&lo>=tails.length-1&&tails[lo]===v&&lo===tails.length-1){}
    }
    return tails.length;
}

export function problem75(): void {
    console.log("Problem 75:");
    if (longestIncreasingSubsequence([0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]) !== 6)
        throw new Error("assertion failed");
    if (longestIncreasingSubsequence([1,2,3]) !== 3) throw new Error("assertion failed");
    if (longestIncreasingSubsequence([3,2,1]) !== 1) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
