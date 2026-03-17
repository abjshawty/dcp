export function isBalanced(s: string): boolean {
    const match: Record<string, string> = { ')': '(', ']': '[', '}': '{' };
    const stack: string[] = [];
    for (const c of s) {
        if ('([{'.includes(c)) {
            stack.push(c);
        } else if (')]}'.includes(c)) {
            if (!stack.length || stack[stack.length - 1] !== match[c]) return false;
            stack.pop();
        }
    }
    return stack.length === 0;
}

export function problem27(): void {
    console.log("Problem 27:");
    if (!isBalanced("([])[]({})" )) throw new Error("assertion failed");
    if ( isBalanced("([)]")       ) throw new Error("assertion failed");
    if ( isBalanced("(((()")      ) throw new Error("assertion failed");
    if (!isBalanced("")           ) throw new Error("assertion failed");
    if (!isBalanced("{[]}")       ) throw new Error("assertion failed");
    console.log("All Tests Passed");
}
