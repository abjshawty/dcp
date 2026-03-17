// minRooms returns the minimum number of rooms to schedule all intervals.
// Sort by start time; use a min-heap of end times.
// This runs in O(n log n) time.
export function minRooms(intervals: [number, number][]): number {
    if (intervals.length === 0) return 0;
    const sorted = [...intervals].sort((a, b) => a[0] - b[0]);
    const ends: number[] = []; // kept sorted as a simple min-heap substitute

    for (const [start, end] of sorted) {
        if (ends.length > 0 && ends[0] <= start) {
            ends.shift(); // reuse earliest-ending room
        }
        // insert end keeping array sorted
        const pos = ends.findIndex(e => e > end);
        if (pos === -1) ends.push(end); else ends.splice(pos, 0, end);
    }
    return ends.length;
}

export function problem21(): void {
    console.log("Problem 21:");
    if (minRooms([[30,75],[0,50],[60,150]]) !== 2) throw new Error("assertion failed");
    if (minRooms([[0,10],[10,20]])          !== 1) throw new Error("assertion failed");
    if (minRooms([[0,10],[0,10]])           !== 2) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
