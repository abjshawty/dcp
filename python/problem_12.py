def staircase(n: int, steps: list[int]) -> int:
    # staircase returns the number of unique ways to climb n steps
    # when you can take any step size from steps.
    # Uses bottom-up DP: ways[i] = sum of ways[i-s] for each s in steps.
    # This runs in O(n * |steps|) time and O(n) space.
    ways = [0] * (n + 1)
    ways[0] = 1  # one way to stand at the bottom
    for i in range(1, n + 1):
        for s in steps:
            if i - s >= 0:
                ways[i] += ways[i - s]
    return ways[n]


def main():
    print("Problem 12:")
    assert staircase(4, [1, 2])    == 5, "assertion failed"
    assert staircase(4, [1, 3, 5]) == 3, "assertion failed"
    assert staircase(0, [1, 2])    == 1, "assertion failed"
    assert staircase(1, [1, 2])    == 1, "assertion failed"
    print("All Tests Passed")
