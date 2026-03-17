export function canBeNonDecreasing(nums: number[]): boolean {
    const a = [...nums];
    let modified = false;
    for (let i = 1; i < a.length; i++) {
        if (a[i] < a[i-1]) {
            if (modified) return false;
            modified = true;
            if (i >= 2 && a[i] < a[i-2]) a[i] = a[i-1];
            else a[i-1] = a[i];
        }
    }
    return true;
}

export function problem79(): void {
    console.log("Problem 79:");
    if (!canBeNonDecreasing([10,5,7]))  throw new Error("assertion failed");
    if ( canBeNonDecreasing([10,5,1]))  throw new Error("assertion failed");
    if (!canBeNonDecreasing([1,2,3]))   throw new Error("assertion failed");
    console.log("All Tests Passed");
}
