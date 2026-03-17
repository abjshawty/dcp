export function largestValuePath(labels: string, edges: [number,number][]): number | null {
    const n = labels.length;
    const adj: number[][] = Array.from({length:n},()=>[]);
    const indegree = new Array(n).fill(0);
    for (const [u,v] of edges) {
        if (u===v) return null;
        adj[u].push(v); indegree[v]++;
    }
    const dp: number[][] = Array.from({length:n},()=>new Array(26).fill(0));
    const queue: number[] = [];
    for (let i=0;i<n;i++) if(indegree[i]===0) queue.push(i);
    let visited=0, best=0;
    while (queue.length) {
        const node = queue.shift()!; visited++;
        dp[node][labels.charCodeAt(node)-65]++;
        best = Math.max(best, ...dp[node]);
        for (const nb of adj[node]) {
            for (let c=0;c<26;c++) dp[nb][c]=Math.max(dp[nb][c],dp[node][c]);
            if (--indegree[nb]===0) queue.push(nb);
        }
    }
    return visited===n ? best : null;
}

export function problem72(): void {
    console.log("Problem 72:");
    if (largestValuePath("ABACA",[[0,1],[0,2],[2,3],[3,4]]) !== 3) throw new Error("assertion failed");
    if (largestValuePath("A",[[0,0]]) !== null) throw new Error("cycle should be null");
    console.log("All Tests Passed");
}
