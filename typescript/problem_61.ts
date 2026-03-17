export function fastPow(x: number, y: number): number {
    if (y === 0) return 1;
    if (y < 0)   return 0;
    const half = fastPow(x, Math.floor(y / 2));
    return y % 2 === 0 ? half * half : half * half * x;
}

export function problem61(): void {
    console.log("Problem 61:");
    if (fastPow(2, 10) !== 1024) throw new Error("assertion failed");
    if (fastPow(3, 0)  !== 1)    throw new Error("assertion failed");
    if (fastPow(5, 3)  !== 125)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
