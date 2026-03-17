// TrieNode holds children and a flag marking end-of-word.
class TrieNode {
    children: Map<string, TrieNode> = new Map();
    isEnd = false;
}

// Trie supports O(|prefix|) insert and O(|prefix| + k) autocomplete.
export class Trie {
    private root = new TrieNode();

    insert(word: string): void {
        let node = this.root;
        for (const ch of word) {
            if (!node.children.has(ch)) node.children.set(ch, new TrieNode());
            node = node.children.get(ch)!;
        }
        node.isEnd = true;
    }

    private collect(node: TrieNode, prefix: string, results: string[]): void {
        if (node.isEnd) results.push(prefix);
        for (const [ch, child] of [...node.children.entries()].sort())
            this.collect(child, prefix + ch, results);
    }

    // autocomplete returns all words sharing the given prefix, sorted.
    autocomplete(prefix: string): string[] {
        let node = this.root;
        for (const ch of prefix) {
            if (!node.children.has(ch)) return [];
            node = node.children.get(ch)!;
        }
        const results: string[] = [];
        this.collect(node, prefix, results);
        return results;
    }
}

export function problem11(): void {
    console.log("Problem 11:");
    const t = new Trie();
    for (const w of ["dog", "deer", "deal"]) t.insert(w);
    const got = t.autocomplete("de");
    if (got.length !== 2 || got[0] !== "deal" || got[1] !== "deer") throw new Error("assertion failed");
    if (t.autocomplete("xyz").length !== 0) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
