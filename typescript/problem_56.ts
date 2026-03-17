export function graphColorable(adj: number[][], k: number): boolean {
    const n = adj.length, colors = new Array(n).fill(0);
    function bt(node: number): boolean {
        if (node === n) return true;
        for (let c = 1; c <= k; c++) {
            if (adj[node].every((e, nb) => e === 0 || colors[nb] !== c)) {
                colors[node] = c;
                if (bt(node + 1)) return true;
                colors[node] = 0;
            }
        }
        return false;
    }
    return bt(0);
}

export function problem56(): void {
    console.log("Problem 56:");
    const t = [[0,1,1],[1,0,1],[1,1,0]];
    if (!graphColorable(t, 3)) throw new Error("assertion failed");
    if ( graphColorable(t, 2)) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
