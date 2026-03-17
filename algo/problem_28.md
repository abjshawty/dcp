# Problem 28 — Text Justification (Palantir)

## Problem Statement
Given a list of words and a line width `k`, return lines that are fully justified: each line has exactly `k` characters, spaces distributed as evenly as possible left-to-right.

## Approach — Greedy Line Filling + Space Distribution

### Step 1 — Greedy word packing
For each line starting at word `i`, greedily add words `j` as long as `sum(lengths) + (j-i-1) gaps ≤ k`.

### Step 2 — Space distribution
For a line with `W` words and `gaps = W-1` gaps:
```
total_spaces = k - sum(word_lengths)
base   = total_spaces // gaps     # every gap gets this many
extra  = total_spaces  % gaps     # first `extra` gaps get one more
```

### Special cases
- **Last line** or **single word**: left-align, pad trailing spaces.

### Example: words=`["the","quick","brown"]`, k=16
```
total_chars = 3+5+5 = 13
total_spaces = 16-13 = 3, gaps = 2
base=1, extra=1
→ "the  quick brown"  (gap 0 gets 2 spaces, gap 1 gets 1)
```

## Complexity
- **Time:** O(total characters) — each word processed once
- **Space:** O(k) per line output
