export function powerSet(nums: number[]): number[][] {
    let result: number[][] = [[]];
    for (const v of nums)
        result = result.concat(result.map(sub => [...sub, v]));
    return result;
}

export function problem37(): void {
    console.log("Problem 37:");
    if (powerSet([1,2,3]).length !== 8) throw new Error("assertion failed");
    if (powerSet([]).length      !== 1) throw new Error("assertion failed");
    if (powerSet([1]).length     !== 2) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
