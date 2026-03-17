export function nthPerfectNumber(n: number): number {
    let count = 0, num = 0;
    while (count < n) {
        num++;
        const s = String(num).split('').reduce((a,c)=>a+parseInt(c),0);
        if (s === 10) count++;
    }
    return num;
}

export function problem70(): void {
    console.log("Problem 70:");
    if (nthPerfectNumber(1) !== 19) throw new Error("assertion failed");
    if (nthPerfectNumber(2) !== 28) throw new Error("assertion failed");
    if (nthPerfectNumber(3) !== 37) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
