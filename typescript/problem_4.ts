// firstMissingPositive finds the smallest positive integer absent from numbers.
// It uses the array itself as a hash map: for each value v in [1..n], it places
// v at index v-1. After rearranging, the first index i where numbers[i] != i+1
// reveals the answer i+1. This runs in O(n) time and O(1) extra space.
export function firstMissingPositive(numbers: number[]): number {
    const n = numbers.length;

    // place each value v into its "home" index v-1, if 1 <= v <= n
    for (let i = 0; i < n; i++) {
        while (numbers[i] > 0 && numbers[i] <= n && numbers[numbers[i] - 1] !== numbers[i]) {
            const j = numbers[i] - 1;
            [numbers[i], numbers[j]] = [numbers[j], numbers[i]]; // swap into place
        }
    }

    // first index whose value is wrong reveals the missing positive
    for (let i = 0; i < n; i++) {
        if (numbers[i] !== i + 1)
            return i + 1;
    }

    return n + 1; // all of 1..n are present
}

export function problem4(): void {
    console.log("Problem 4:");
    if (firstMissingPositive([3, 4, -1, 1]) !== 2) throw new Error("assertion failed");
    if (firstMissingPositive([1, 2, 0])      !== 3) throw new Error("assertion failed");
    if (firstMissingPositive([1, 2, 3])      !== 4) throw new Error("assertion failed");
    if (firstMissingPositive([7, 8, 9])      !== 1) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
