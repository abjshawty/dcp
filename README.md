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
| 24 | Medium     | Google     | Locking Binary Tree                    | `algo/problem_24.md`         |
| 25 | Hard       | Facebook   | Regular Expression Matching            | `algo/problem_25.md`         |
| 26 | Medium     | Google     | Remove Kth Last from Linked List       | `algo/problem_26.md`         |
| 27 | Easy       | Facebook   | Balanced Brackets                      | `algo/problem_27.md`         |
| 28 | Medium     | Palantir   | Text Justification                     | `algo/problem_28.md`         |
| 29 | Easy       | Amazon     | Run-Length Encoding                    | `algo/problem_29.md`         |
| 30 | Medium     | Facebook   | Trapping Rain Water                    | `algo/problem_30.md`         |
| 31 | Easy       | Google     | Edit Distance                          | `algo/problem_31.md`         |
| 32 | Hard       | Jane Street| Currency Arbitrage                     | `algo/problem_32.md`         |
| 33 | Easy       | Microsoft  | Running Median                         | `algo/problem_33.md`         |
| 34 | Medium     | Quora      | Minimum Palindrome Insertion           | `algo/problem_34.md`         |
| 35 | Hard       | Google     | RGB Sort (Dutch National Flag)         | `algo/problem_35.md`         |
| 36 | Medium     | Dropbox    | Second Largest in BST                  | `algo/problem_36.md`         |
| 37 | Easy       | Google     | Power Set                              | `algo/problem_37.md`         |
| 38 | Hard       | Microsoft  | N-Queens                               | `algo/problem_38.md`         |
| 39 | Medium     | Dropbox    | Conway's Game of Life                  | `algo/problem_39.md`         |
| 40 | Hard       | Google     | Single Number (others appear 3×)       | `algo/problem_40.md`         |
| 41 | Medium     | Facebook   | Flight Itinerary (Eulerian Path)       | `algo/problem_41.md`         |
| 42 | Hard       | Google     | Subset Sum                             | `algo/problem_42.md`         |
| 43 | Easy       | Amazon     | Max Stack                              | `algo/problem_43.md`         |

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