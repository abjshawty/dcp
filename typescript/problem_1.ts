// findPairWithSum checks if any two numbers in the array sum to k.
// It uses a Set to track numbers seen so far. For each number n,
// it checks if the complement (k-n) was already seen — if so, a valid
// pair exists. This runs in O(n) time and O(n) space.
export function findPairWithSum(numbers: number[], k: number): boolean {
    const seen = new Set<number>();
    for (const n of numbers) {
        if (seen.has(k - n)) // check if the complement was seen earlier
            return true;
        seen.add(n); // record this number for future iterations
    }
    return false;
}

export function problem1(): void {
    console.log("Problem 1:");
    if (findPairWithSum([10, 15, 3, 7], 17)  !== true)  throw new Error("assertion failed");
    if (findPairWithSum([10, 15, 3, 7], 100) !== false) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
