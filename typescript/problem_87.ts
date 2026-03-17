export function validateRules(rules: string[]): boolean {
    const xLo=new Map<string,number>(), xHi=new Map<string,number>();
    const yLo=new Map<string,number>(), yHi=new Map<string,number>();
    const mx=(m:Map<string,number>,k:string,v:number)=>m.set(k,Math.max(m.get(k)??-Infinity,v));
    const mn=(m:Map<string,number>,k:string,v:number)=>m.set(k,Math.min(m.get(k)??Infinity,v));
    for (const rule of rules) {
        const [a,dir,b]=rule.split(' '); const eps=1;
        const yb=yLo.get(b)??0, yt=yHi.get(b)??0, xb=xLo.get(b)??0, xt=xHi.get(b)??0;
        if(dir==='N')  mx(yLo,a,yb+eps);
        else if(dir==='S')  mn(yHi,a,yt-eps);
        else if(dir==='E')  mx(xLo,a,xb+eps);
        else if(dir==='W')  mn(xHi,a,xt-eps);
        else if(dir==='NE'){mx(yLo,a,yb+eps);mx(xLo,a,xb+eps);}
        else if(dir==='NW'){mx(yLo,a,yb+eps);mn(xHi,a,xt-eps);}
        else if(dir==='SE'){mn(yHi,a,yt-eps);mx(xLo,a,xb+eps);}
        else if(dir==='SW'){mn(yHi,a,yt-eps);mn(xHi,a,xt-eps);}
        for(const p of new Set([...xLo.keys(),...xHi.keys()]))
            if((xLo.get(p)??-Infinity)>=(xHi.get(p)??Infinity)) return false;
        for(const p of new Set([...yLo.keys(),...yHi.keys()]))
            if((yLo.get(p)??-Infinity)>=(yHi.get(p)??Infinity)) return false;
    }
    return true;
}

export function problem87(): void {
    console.log("Problem 87:");
    if ( validateRules(["A N B","B NE C","C N A"])) throw new Error("should be invalid");
    if (!validateRules(["A NW B","A N B"]))         throw new Error("should be valid");
    console.log("All Tests Passed");
}
