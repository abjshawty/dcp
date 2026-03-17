export function wordInMatrix(matrix: string[][], word: string): boolean {
    const rows = matrix.length, cols = matrix[0].length, n = word.length;
    for (let r = 0; r < rows; r++)
        for (let c = 0; c <= cols - n; c++)
            if ([...word].every((ch, i) => matrix[r][c+i] === ch)) return true;
    for (let c = 0; c < cols; c++)
        for (let r = 0; r <= rows - n; r++)
            if ([...word].every((ch, i) => matrix[r+i][c] === ch)) return true;
    return false;
}

export function problem63(): void {
    console.log("Problem 63:");
    const m = [['F','A','C','I'],['O','B','Q','P'],['A','N','O','B'],['M','A','S','S']];
    if (!wordInMatrix(m, "FOAM")) throw new Error("assertion failed");
    if (!wordInMatrix(m, "MASS")) throw new Error("assertion failed");
    if ( wordInMatrix(m, "NOPE")) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
