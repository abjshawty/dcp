# Problem 10 — Job Scheduler (Apple)

## Problem Statement
Implement a job scheduler that takes a function `f` and an integer `n`, and calls `f` after `n` milliseconds.

## Approach — Delayed Execution

The key insight is simply to delay execution without blocking the caller (where the language supports async).

| Language   | Mechanism |
|------------|-----------|
| Go         | `go func()` + `time.Sleep` in a goroutine |
| Python     | `threading.Timer(n/1000, f).start()` |
| TypeScript | `setTimeout(f, n)` (event loop) |
| Rust       | `thread::spawn` + `thread::sleep` |
| Lua        | Synchronous busy-wait (`os.clock`) — Lua has no threads |
| C          | `Sleep` (Windows) / `usleep` (POSIX) — synchronous for simplicity |

In production, you'd typically use a priority-queue-based timer wheel for scheduling many jobs efficiently. For this problem a single delayed call is sufficient.

## Complexity
- **Time:** O(1) to schedule
- **Space:** O(1)
