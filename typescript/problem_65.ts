export function spiralOrder(matrix: number[][]): number[] {
    let top=0, bottom=matrix.length-1, left=0, right=matrix[0].length-1;
    const result: number[] = [];
    while (top<=bottom && left<=right) {
        for (let c=left;c<=right;c++) result.push(matrix[top][c]); top++;
        for (let r=top;r<=bottom;r++) result.push(matrix[r][right]); right--;
        if (top<=bottom) { for (let c=right;c>=left;c--) result.push(matrix[bottom][c]); bottom--; }
        if (left<=right) { for (let r=bottom;r>=top;r--) result.push(matrix[r][left]); left++; }
    }
    return result;
}

export function problem65(): void {
    console.log("Problem 65:");
    const m = [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20]];
    const exp = [1,2,3,4,5,10,15,20,19,18,17,16,11,6,7,8,9,14,13,12];
    if (JSON.stringify(spiralOrder(m)) !== JSON.stringify(exp)) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
