export function sortRGB(arr: string[]): void {
    let lo = 0, mid = 0, hi = arr.length - 1;
    while (mid <= hi) {
        if (arr[mid] === 'R') {
            [arr[lo], arr[mid]] = [arr[mid], arr[lo]]; lo++; mid++;
        } else if (arr[mid] === 'G') {
            mid++;
        } else {
            [arr[mid], arr[hi]] = [arr[hi], arr[mid]]; hi--;
        }
    }
}

export function problem35(): void {
    console.log("Problem 35:");
    const arr = ['G','B','R','R','B','R','G'];
    sortRGB(arr);
    if (JSON.stringify(arr) !== JSON.stringify(['R','R','R','G','G','B','B']))
        throw new Error("assertion failed");
    const arr2 = ['B','G','R'];
    sortRGB(arr2);
    if (JSON.stringify(arr2) !== JSON.stringify(['R','G','B']))
        throw new Error("assertion failed");
    console.log("All Tests Passed");
}
