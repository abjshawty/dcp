export function trapWater(heights: number[]): number {
    if (!heights.length) return 0;
    let left = 0, right = heights.length - 1;
    let leftMax = 0, rightMax = 0, water = 0;
    while (left < right) {
        if (heights[left] < heights[right]) {
            if (heights[left] >= leftMax) leftMax = heights[left];
            else water += leftMax - heights[left];
            left++;
        } else {
            if (heights[right] >= rightMax) rightMax = heights[right];
            else water += rightMax - heights[right];
            right--;
        }
    }
    return water;
}

export function problem30(): void {
    console.log("Problem 30:");
    if (trapWater([2,1,2])                           !== 1) throw new Error("assertion failed");
    if (trapWater([3,0,1,3,0,5])                     !== 8) throw new Error("assertion failed");
    if (trapWater([0,1,0,2,1,0,1,3,2,1,2,1])         !== 6) throw new Error("assertion failed");
    if (trapWater([])                                !== 0) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
