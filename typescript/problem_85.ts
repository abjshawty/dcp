export function selectByBit(x: number, y: number, b: number): number {
    return x * b + y * (1 - b);
}

export function problem85(): void {
    console.log("Problem 85:");
    if (selectByBit(10,20,1) !== 10) throw new Error("assertion failed");
    if (selectByBit(10,20,0) !== 20) throw new Error("assertion failed");
    if (selectByBit(5,7,1)   !== 5)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
