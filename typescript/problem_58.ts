export function searchRotated(arr: number[], target: number): number {
    let lo = 0, hi = arr.length - 1;
    while (lo <= hi) {
        const mid = (lo + hi) >> 1;
        if (arr[mid] === target) return mid;
        if (arr[lo] <= arr[mid]) {
            if (arr[lo] <= target && target < arr[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {
            if (arr[mid] < target && target <= arr[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

export function problem58(): void {
    console.log("Problem 58:");
    if (searchRotated([13,18,25,2,8,10], 8)  !== 4)  throw new Error("assertion failed");
    if (searchRotated([13,18,25,2,8,10], 13) !== 0)  throw new Error("assertion failed");
    if (searchRotated([13,18,25,2,8,10], 99) !== -1) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
