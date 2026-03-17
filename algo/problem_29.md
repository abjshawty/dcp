# Problem 29 — Run-Length Encoding (Amazon)

## Problem Statement
Implement run-length encoding (`encode`) and decoding (`decode`). Input has no digits; output format is `<count><char>` repeated.

## Approach — Linear Scan

### Encode
Walk through the string counting consecutive identical characters. When the character changes (or at the end), emit `<count><char>`.

```
"AAAABBBCCDAA"
A×4, B×3, C×2, D×1, A×2
→ "4A3B2C1D2A"
```

### Decode
Parse pairs: read digits to get the count, read the next character, repeat it `count` times.

```
"4A3B2C1D2A"
4×A, 3×B, 2×C, 1×D, 2×A
→ "AAAABBBCCDAA"
```

### Edge cases
- Empty string → empty string.
- Single character → `"1X"`.

These two functions are inverses: `decode(encode(s)) == s` for all valid inputs.

## Complexity
- **Encode:** O(n) time, O(n) output space
- **Decode:** O(n) time, O(m) output space (m = decoded length)
