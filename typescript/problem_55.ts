export class URLShortener55 {
    private s2l = new Map<string, string>();
    private l2s = new Map<string, string>();
    shorten(url: string): string {
        if (this.l2s.has(url)) return this.l2s.get(url)!;
        const short = Math.random().toString(36).slice(2, 8);
        this.s2l.set(short, url); this.l2s.set(url, short);
        return short;
    }
    restore(short: string): string | null { return this.s2l.get(short) ?? null; }
}

export function problem55(): void {
    console.log("Problem 55:");
    const us = new URLShortener55();
    const s1 = us.shorten("https://example.com");
    if (!s1.length) throw new Error("assertion failed");
    if (us.restore(s1) !== "https://example.com") throw new Error("assertion failed");
    if (us.shorten("https://example.com") !== s1) throw new Error("same URL same short");
    if (us.restore("notexist") !== null) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
