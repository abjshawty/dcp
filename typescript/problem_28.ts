export function justifyText(words: string[], k: number): string[] {
    const lines: string[] = [];
    let i = 0;
    while (i < words.length) {
        let lineLen = words[i].length;
        let j = i + 1;
        while (j < words.length && lineLen + 1 + words[j].length <= k) {
            lineLen += 1 + words[j].length;
            j++;
        }
        const lineWords = words.slice(i, j);
        const gaps = j - i - 1;
        if (j === words.length || gaps === 0) {
            const line = lineWords.join(' ');
            lines.push(line + ' '.repeat(k - line.length));
        } else {
            const totalChars = lineWords.reduce((s, w) => s + w.length, 0);
            const totalSpaces = k - totalChars;
            const base = Math.floor(totalSpaces / gaps);
            const extra = totalSpaces % gaps;
            let line = '';
            for (let idx = 0; idx < lineWords.length; idx++) {
                line += lineWords[idx];
                if (idx < gaps) line += ' '.repeat(base) + (idx < extra ? ' ' : '');
            }
            lines.push(line);
        }
        i = j;
    }
    return lines;
}

export function problem28(): void {
    console.log("Problem 28:");
    const words = ["the","quick","brown","fox","jumps","over","the","lazy","dog"];
    const result = justifyText(words, 16);
    const expected = ["the  quick brown", "fox  jumps  over", "the   lazy   dog"];
    if (JSON.stringify(result) !== JSON.stringify(expected)) throw new Error("assertion failed");
    if (result.some(l => l.length !== 16)) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
