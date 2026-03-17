function simpleHash(s: string): string {
    let h = 0;
    for (let i = 0; i < s.length; i++) h = (Math.imul(31, h) + s.charCodeAt(i)) | 0;
    return h.toString(16);
}

export class FileSyncer59 {
    files = new Map<string, string>();
    put(name: string, content: string): void { this.files.set(name, content); }
    checksum(name: string): string {
        return simpleHash(this.files.get(name) ?? '');
    }
    syncFrom(other: FileSyncer59): string[] {
        const transferred: string[] = [];
        for (const [name, content] of other.files) {
            if (this.checksum(name) !== other.checksum(name)) {
                this.files.set(name, content);
                transferred.push(name);
            }
        }
        return transferred;
    }
}

export function problem59(): void {
    console.log("Problem 59:");
    const a = new FileSyncer59(), b = new FileSyncer59();
    a.put("foo.txt", "hello world"); a.put("bar.txt", "same");
    b.put("bar.txt", "same");
    const changed = b.syncFrom(a);
    if (JSON.stringify(changed) !== JSON.stringify(["foo.txt"])) throw new Error("assertion failed");
    if (b.files.get("foo.txt") !== "hello world") throw new Error("assertion failed");
    console.log("All Tests Passed");
}
