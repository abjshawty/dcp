function tossBiased66(): number { return Math.random() < 0.7 ? 1 : 0; }

export function unbiasedCoin(): number {
    while (true) {
        const a = tossBiased66(), b = tossBiased66();
        if (a === 0 && b === 1) return 0;
        if (a === 1 && b === 0) return 1;
    }
}

export function problem66(): void {
    console.log("Problem 66:");
    const counts = [0, 0];
    for (let i = 0; i < 10000; i++) counts[unbiasedCoin()]++;
    if (counts[0] < 4000 || counts[1] < 4000) throw new Error("bad distribution");
    console.log("All Tests Passed");
}
