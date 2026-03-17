// maxSubarrayOfSizeK returns the maximum value in each sliding window of size k.
// Uses a monotonic deque of indices in decreasing value order.
// This runs in O(n) time and O(k) space.
export function maxSubarrayOfSizeK(nums: number[], k: number): number[] {
    const deque: number[] = []; // stores indices; front is current window max
    const result: number[] = [];

    for (let i = 0; i < nums.length; i++) {
        // remove indices outside the window
        while (deque.length > 0 && deque[0] < i - k + 1) deque.shift();
        // remove smaller elements from the back
        while (deque.length > 0 && nums[deque[deque.length - 1]] < nums[i]) deque.pop();
        deque.push(i);
        if (i >= k - 1) result.push(nums[deque[0]]);
    }
    return result;
}

export function problem18(): void {
    console.log("Problem 18:");
    const got = maxSubarrayOfSizeK([10, 5, 2, 7, 8, 7], 3);
    const exp = [10, 7, 8, 8];
    if (got.length !== exp.length || got.some((v, i) => v !== exp[i]))
        throw new Error("assertion failed");
    console.log("All Tests Passed");
}
