class Reader82ts {
    private pos = 0; private buf = '';
    constructor(private content: string) {}
    private read7(): string { const c=this.content.slice(this.pos,this.pos+7); this.pos+=c.length; return c; }
    readN(n: number): string {
        while (this.buf.length < n) { const c=this.read7(); if(!c) break; this.buf+=c; }
        const result=this.buf.slice(0,n); this.buf=this.buf.slice(n); return result;
    }
}

export function problem82(): void {
    console.log("Problem 82:");
    const r = new Reader82ts("Hello world");
    if (r.readN(5) !== "Hello") throw new Error("assertion failed");
    if (r.readN(1) !== " ")     throw new Error("assertion failed");
    if (r.readN(5) !== "world") throw new Error("assertion failed");
    if (r.readN(5) !== "")      throw new Error("assertion failed");
    console.log("All Tests Passed");
}
