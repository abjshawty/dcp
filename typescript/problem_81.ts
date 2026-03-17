export function phoneLetters(mapping: Record<string, string[]>, digits: string): string[] {
    if (!digits) return [''];
    const result: string[] = [];
    for (const letter of mapping[digits[0]])
        for (const rest of phoneLetters(mapping, digits.slice(1)))
            result.push(letter + rest);
    return result;
}

export function problem81(): void {
    console.log("Problem 81:");
    const m: Record<string,string[]> = {'2':['a','b','c'],'3':['d','e','f']};
    const got = phoneLetters(m, "23");
    if (got.length !== 9) throw new Error("assertion failed");
    if (!got.includes('ad') || !got.includes('cf')) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
