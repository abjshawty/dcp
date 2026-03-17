export function hasArbitrage(rates: number[][]): boolean {
    const n = rates.length;
    const dist = new Array(n).fill(0);
    for (let k = 0; k < n - 1; k++)
        for (let i = 0; i < n; i++)
            for (let j = 0; j < n; j++) {
                if (rates[i][j] === 0) continue;
                const w = -Math.log(rates[i][j]);
                if (dist[i] + w < dist[j]) dist[j] = dist[i] + w;
            }
    for (let i = 0; i < n; i++)
        for (let j = 0; j < n; j++) {
            if (rates[i][j] === 0) continue;
            if (dist[i] + (-Math.log(rates[i][j])) < dist[j]) return true;
        }
    return false;
}

export function problem32(): void {
    console.log("Problem 32:");
    const arb  = [[1,0.9,0.8],[1.2,1,0.9],[1.4,1.2,1]];
    const fair = [[1,2,4],[0.5,1,2],[0.25,0.5,1]];
    if (!hasArbitrage(arb))  throw new Error("assertion failed");
    if ( hasArbitrage(fair)) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
