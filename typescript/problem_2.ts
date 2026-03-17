// productOfArrayExceptSelf returns an array where each element is the product
// of all other elements in the input. Two passes: prefix then suffix.
// This runs in O(n) time and O(n) space without using division.
export function productOfArrayExceptSelf(numbers: number[]): number[] {
    const n = numbers.length;
    const result = new Array<number>(n);

    // first pass: result[i] = product of all elements to the left of i
    result[0] = 1;
    for (let i = 1; i < n; i++)
        result[i] = result[i - 1] * numbers[i - 1];

    // second pass: multiply in the product of all elements to the right of i
    let suffix = 1;
    for (let i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= numbers[i];
    }

    return result;
}

export function problem2(): void {
    console.log("Problem 2:");
    const result   = productOfArrayExceptSelf([1, 2, 3, 4, 5]);
    const expected = [120, 60, 40, 30, 24];
    for (let i = 0; i < expected.length; i++)
        if (result[i] !== expected[i]) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
