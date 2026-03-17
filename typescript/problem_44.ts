export function countInversions(arr: number[]): number {
    function mergeSort(a: number[]): [number[], number] {
        if (a.length <= 1) return [a, 0];
        const mid = a.length >> 1;
        const [left, lc] = mergeSort(a.slice(0, mid));
        const [right, rc] = mergeSort(a.slice(mid));
        const merged: number[] = [];
        let i = 0, j = 0, mc = 0;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) merged.push(left[i++]);
            else { merged.push(right[j++]); mc += left.length - i; }
        }
        return [[...merged, ...left.slice(i), ...right.slice(j)], lc + rc + mc];
    }
    return mergeSort(arr)[1];
}

export function problem44(): void {
    console.log("Problem 44:");
    if (countInversions([2,4,1,3,5]) !== 3)  throw new Error("assertion failed");
    if (countInversions([5,4,3,2,1]) !== 10) throw new Error("assertion failed");
    if (countInversions([1,2,3])     !== 0)  throw new Error("assertion failed");
    console.log("All Tests Passed");
}
