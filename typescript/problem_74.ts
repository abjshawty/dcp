export function countInMultTable(n: number, x: number): number {
    let count = 0;
    for (let i = 1; i <= n; i++)
        if (x % i === 0 && x / i <= n) count++;
    return count;
}

export function problem74(): void {
    console.log("Problem 74:");
    if (countInMultTable(6,12) !== 4) throw new Error("assertion failed");
    if (countInMultTable(3,6)  !== 2) throw new Error("assertion failed");
    if (countInMultTable(1,1)  !== 1) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
