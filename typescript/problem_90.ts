export function randomExcluding(n: number, exclude: number[]): number {
    const excSet = new Set(exclude);
    const valid = Array.from({length:n},(_,i)=>i).filter(i=>!excSet.has(i));
    return valid[Math.floor(Math.random()*valid.length)];
}

export function problem90(): void {
    console.log("Problem 90:");
    for (let i=0;i<100;i++) if(randomExcluding(5,[0,1,2,4])!==3) throw new Error("assertion failed");
    const counts:Record<number,number>={};
    for(let i=0;i<1000;i++){const v=randomExcluding(5,[2]);counts[v]=(counts[v]??0)+1;}
    for(const k of [0,1,3,4]) if((counts[k]??0)<100) throw new Error("bad distribution");
    console.log("All Tests Passed");
}
