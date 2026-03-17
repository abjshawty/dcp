export function countIslands(grid: number[][]): number {
    const rows=grid.length, cols=grid[0].length;
    const visited=Array.from({length:rows},()=>new Array(cols).fill(false));
    let count=0;
    function dfs(r:number,c:number){
        if(r<0||r>=rows||c<0||c>=cols||visited[r][c]||grid[r][c]===0)return;
        visited[r][c]=true; dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1);
    }
    for(let r=0;r<rows;r++) for(let c=0;c<cols;c++) if(!visited[r][c]&&grid[r][c]===1){count++;dfs(r,c);}
    return count;
}

export function problem84(): void {
    console.log("Problem 84:");
    const g = [[1,0,0,0,0],[0,0,1,1,0],[0,1,1,0,0],[0,0,0,0,0],[1,1,0,0,1],[1,1,0,0,1]];
    if (countIslands(g) !== 4) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
