function rand7ts71(): number { return Math.floor(Math.random()*7)+1; }

export function rand5ts71(): number {
    while (true) { const v = rand7ts71(); if (v <= 5) return v; }
}

export function problem71(): void {
    console.log("Problem 71:");
    const counts = new Array(6).fill(0);
    for (let i=0;i<50000;i++) { const v=rand5ts71(); if(v<1||v>5) throw new Error("out of range"); counts[v]++; }
    for (let i=1;i<=5;i++) if(counts[i]<7000||counts[i]>13000) throw new Error("bad distribution");
    console.log("All Tests Passed");
}
