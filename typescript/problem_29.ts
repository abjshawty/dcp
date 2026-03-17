export function rleEncode(s: string): string {
    if (!s) return '';
    let result = '';
    let count = 1;
    for (let i = 1; i < s.length; i++) {
        if (s[i] === s[i - 1]) { count++; }
        else { result += `${count}${s[i-1]}`; count = 1; }
    }
    result += `${count}${s[s.length - 1]}`;
    return result;
}

export function rleDecode(s: string): string {
    let result = '';
    let i = 0;
    while (i < s.length) {
        let j = i;
        while (j < s.length && s[j] >= '0' && s[j] <= '9') j++;
        result += s[j].repeat(parseInt(s.slice(i, j), 10));
        i = j + 1;
    }
    return result;
}

export function problem29(): void {
    console.log("Problem 29:");
    if (rleEncode("AAAABBBCCDAA") !== "4A3B2C1D2A") throw new Error("assertion failed");
    if (rleDecode("4A3B2C1D2A")  !== "AAAABBBCCDAA") throw new Error("assertion failed");
    if (rleEncode("A")           !== "1A")           throw new Error("assertion failed");
    if (rleDecode("1A")          !== "A")            throw new Error("assertion failed");
    if (rleEncode("")            !== "")             throw new Error("assertion failed");
    console.log("All Tests Passed");
}
