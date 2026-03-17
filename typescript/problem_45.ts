function rand5ts(): number { return Math.floor(Math.random() * 5) + 1; }

export function rand7ts(): number {
    while (true) {
        const n = (rand5ts() - 1) * 5 + (rand5ts() - 1);
        if (n < 21) return n % 7 + 1;
    }
}

export function problem45(): void {
    console.log("Problem 45:");
    const counts = new Array(8).fill(0);
    for (let i = 0; i < 70000; i++) {
        const v = rand7ts();
        if (v < 1 || v > 7) throw new Error("out of range");
        counts[v]++;
    }
    for (let i = 1; i <= 7; i++)
        if (counts[i] < 7000 || counts[i] > 13000) throw new Error("bad distribution");
    console.log("All Tests Passed");
}
