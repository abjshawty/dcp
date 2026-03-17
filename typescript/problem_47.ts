export function maxProfit(prices: number[]): number {
    if (prices.length < 2) return 0;
    let minPrice = prices[0], best = 0;
    for (const p of prices.slice(1)) {
        best = Math.max(best, p - minPrice);
        minPrice = Math.min(minPrice, p);
    }
    return best;
}

export function problem47(): void {
    console.log("Problem 47:");
    if (maxProfit([9,11,8,5,7,10]) !== 5) throw new Error("assertion failed");
    if (maxProfit([1,2,3,4,5])     !== 4) throw new Error("assertion failed");
    if (maxProfit([5,4,3,2,1])     !== 0) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
