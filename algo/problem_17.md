# Problem 17 — File System Longest Path (Google)

## Problem Statement
Given a filesystem encoded as a newline+tab-indented string, return the character length of the longest absolute path to a file. Directories don't contain `.`; files do.

## Approach — Depth Stack

Parse line by line:
1. **Depth** = number of leading `\t` characters.
2. **Name** = the rest of the line (after tabs).
3. `path_len = stack[depth] + len(name)` where `stack[depth]` is the cumulative length of the parent path (including its `/`).
4. `stack[depth+1] = path_len + 1` (store for children; `+1` for the `/` separator).
5. If `name` contains `.`, it's a file — update `best`.

`stack[0] = 0` means root-level entries have length equal to their own name.

### Example: `"dir\n\tsubdir2\n\t\tfile2.ext"`

```
depth=0, name="dir",       path=3,  stack[1]=4
depth=1, name="subdir2",   path=11, stack[2]=12
depth=2, name="file2.ext", path=21  ← file, best=21
```

## Complexity
- **Time:** O(n)
- **Space:** O(d) where d = max directory depth
