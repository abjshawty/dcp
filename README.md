# Daily Coding Problems

Solutions to problems from the [Daily Coding Problem](https://www.dailycodingproblem.com/) newsletter, implemented in six languages with algorithmic explanations for each problem.

---

## Languages

| Folder       | Language              | Entry point  | Run command                          |
|--------------|-----------------------|--------------|--------------------------------------|
| `go/`        | Go                    | `main.go`    | `go run .`                           |
| `python/`    | Python 3              | `main.py`    | `python main.py`                     |
| `typescript/`| TypeScript (Bun)      | `main.ts`    | `bun run main.ts`                    |
| `lua/`       | Lua 5.4               | `main.lua`   | `lua main.lua`                       |
| `rust/`      | Rust                  | `main.rs`    | `cargo run`                          |
| `c/`         | C (C99)               | `main.c`     | `gcc *.c -lm -o out && ./out`        |

Each folder is self-contained. Every problem is in its own file (e.g. `problem_7.go`) and called from the language's `main` entry point.

---

## Problems

| #  | Difficulty | Company    | Title                                  | Algo file                    |
|----|------------|------------|----------------------------------------|------------------------------|
| 1  | Easy       | Google     | Sum of Two Numbers                     | `algo/problem_1.md`          |
| 2  | Hard       | Uber       | Product of Array Except Self           | `algo/problem_2.md`          |
| 3  | Medium     | Google     | Serialize and Deserialize Binary Tree  | `algo/problem_3.md`          |
| 4  | Hard       | Stripe     | First Missing Positive Integer         | `algo/problem_4.md`          |
| 5  | Medium     | Jane Street| Implement car and cdr                  | `algo/problem_5.md`          |
| 6  | Hard       | Google     | XOR Linked List                        | `algo/problem_6.md`          |
| 7  | Medium     | Facebook   | Decode Ways                            | `algo/problem_7.md`          |
| 8  | Easy       | Google     | Count Unival Subtrees                  | `algo/problem_8.md`          |
| 9  | Hard       | Airbnb     | Largest Sum of Non-Adjacent Numbers    | `algo/problem_9.md`          |
| 10 | Medium     | Apple      | Job Scheduler                          | `algo/problem_10.md`         |
| 11 | Medium     | Twitter    | Autocomplete System (Trie)             | `algo/problem_11.md`         |
| 12 | Hard       | Amazon     | Staircase Climbing                     | `algo/problem_12.md`         |
| 13 | Hard       | Amazon     | Longest Substring with K Distinct Chars| `algo/problem_13.md`         |
| 14 | Medium     | Google     | Monte Carlo Pi Estimation              | `algo/problem_14.md`         |
| 15 | Medium     | Facebook   | Random Element from Stream             | `algo/problem_15.md`         |
| 16 | Easy       | Twitter    | Order Log (Circular Buffer)            | `algo/problem_16.md`         |
| 17 | Hard       | Google     | File System Longest Path               | `algo/problem_17.md`         |
| 18 | Hard       | Google     | Maximum Values of Subarrays            | `algo/problem_18.md`         |
| 19 | Medium     | Facebook   | Minimum Cost to Paint Houses           | `algo/problem_19.md`         |
| 20 | Easy       | Google     | Intersection of Two Linked Lists       | `algo/problem_20.md`         |
| 21 | Easy       | Snapchat   | Minimum Number of Classrooms           | `algo/problem_21.md`         |
| 22 | Medium     | Microsoft  | Word Break Reconstruction              | `algo/problem_22.md`         |
| 23 | Easy       | Google     | Shortest Path in Boolean Matrix        | `algo/problem_23.md`         |

---

## Structure

```
dcp/
├── algo/           # Markdown explanations of each problem's approach
├── c/              # C implementations (problem_N.c + problem_N.h + main.c)
├── go/             # Go implementations (problem_N.go + main.go + go.mod)
├── lua/            # Lua implementations (problem_N.lua + main.lua)
├── python/         # Python implementations (problem_N.py + main.py)
├── rust/           # Rust implementations (problem_N.rs + main.rs)
├── typescript/     # TypeScript implementations (problem_N.ts + main.ts)
├── QUESTIONS.md    # Original problem statements
└── README.md
```