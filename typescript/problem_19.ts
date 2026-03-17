// minCostPaint returns the minimum cost to paint N houses with K colors
// such that no two adjacent houses share the same color.
// Uses bottom-up DP. This runs in O(N*K) time and O(N*K) space.
export function minCostPaint(costs: number[][]): number {
    if (costs.length === 0) return 0;
    const n = costs.length, k = costs[0].length;
    const dp = costs.map(row => [...row]);

    for (let i = 1; i < n; i++)
        for (let c = 0; c < k; c++) {
            let minPrev = Infinity;
            for (let p = 0; p < k; p++)
                if (p !== c && dp[i-1][p] < minPrev) minPrev = dp[i-1][p];
            dp[i][c] += minPrev;
        }

    return Math.min(...dp[n - 1]);
}

export function problem19(): void {
    console.log("Problem 19:");
    const costs = [[17, 2, 17], [16, 16, 5], [14, 3, 19]];
    if (minCostPaint(costs)       !== 10) throw new Error("assertion failed");
    if (minCostPaint([[1, 2, 3]]) !== 1)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
