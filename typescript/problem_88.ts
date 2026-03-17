export function intDivide(a: number, b: number): number {
    let q = 0;
    while (a >= b) { a -= b; q++; }
    return q;
}

export function problem88(): void {
    console.log("Problem 88:");
    if (intDivide(10,3)   !== 3)  throw new Error("assertion failed");
    if (intDivide(7,2)    !== 3)  throw new Error("assertion failed");
    if (intDivide(100,10) !== 10) throw new Error("assertion failed");
    if (intDivide(1,1)    !== 1)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
