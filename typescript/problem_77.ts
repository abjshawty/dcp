export function mergeIntervals(intervals: [number,number][]): [number,number][] {
    const sorted = [...intervals].sort((a,b)=>a[0]-b[0]);
    const result: [number,number][] = [sorted[0]];
    for (const [s,e] of sorted.slice(1)) {
        const last = result[result.length-1];
        if (s <= last[1]) last[1] = Math.max(last[1], e);
        else result.push([s,e]);
    }
    return result;
}

export function problem77(): void {
    console.log("Problem 77:");
    const got = mergeIntervals([[1,3],[5,8],[4,10],[20,25]]);
    if (JSON.stringify(got) !== JSON.stringify([[1,3],[4,10],[20,25]]))
        throw new Error("assertion failed");
    console.log("All Tests Passed");
}
