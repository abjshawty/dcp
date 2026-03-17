export function singleNumber(nums: number[]): number {
    let result = 0;
    for (let bit = 0; bit < 32; bit++) {
        const total = nums.reduce((s, n) => s + ((n >> bit) & 1), 0);
        if (total % 3 !== 0) result |= (1 << bit);
    }
    return result;
}

export function problem40(): void {
    console.log("Problem 40:");
    if (singleNumber([6,1,3,3,3,6,6]) !== 1)  throw new Error("assertion failed");
    if (singleNumber([13,19,13,13])   !== 19) throw new Error("assertion failed");
    if (singleNumber([0,0,0,5])       !== 5)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
