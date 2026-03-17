export function findItinerary(flights: [string, string][], start: string): string[] | null {
    const graph: Map<string, string[]> = new Map();
    for (const [src, dst] of flights) {
        if (!graph.has(src)) graph.set(src, []);
        graph.get(src)!.push(dst);
    }
    for (const [, dsts] of graph) dsts.sort();

    const result: string[] = [];
    function dfs(airport: string): void {
        const dsts = graph.get(airport) ?? [];
        while (dsts.length > 0) { dfs(dsts.shift()!); }
        result.unshift(airport);
    }
    dfs(start);
    return result.length === flights.length + 1 ? result : null;
}

export function problem41(): void {
    console.log("Problem 41:");
    const f1: [string,string][] = [['SFO','HKO'],['YYZ','SFO'],['YUL','YYZ'],['HKO','ORD']];
    if (JSON.stringify(findItinerary(f1,'YUL')) !== JSON.stringify(['YUL','YYZ','SFO','HKO','ORD']))
        throw new Error("assertion failed");
    const f2: [string,string][] = [['SFO','COM'],['COM','YYZ']];
    if (findItinerary(f2,'COM') !== null) throw new Error("assertion failed");
    const f3: [string,string][] = [['A','B'],['A','C'],['B','C'],['C','A']];
    if (JSON.stringify(findItinerary(f3,'A')) !== JSON.stringify(['A','B','C','A','C']))
        throw new Error("assertion failed");
    console.log("All Tests Passed");
}
