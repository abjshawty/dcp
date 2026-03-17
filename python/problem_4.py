def first_missing_positive(numbers: list[int]) -> int:
    # first_missing_positive finds the smallest positive integer absent from numbers.
    # It uses the array itself as a hash map: for each value v in [1..n], it places
    # v at index v-1. After rearranging, the first index i where numbers[i] != i+1
    # reveals the answer i+1. This runs in O(n) time and O(1) extra space.
    n = len(numbers)

    # place each value v into its "home" index v-1, if 1 <= v <= n
    for i in range(n):
        while 1 <= numbers[i] <= n and numbers[numbers[i] - 1] != numbers[i]:
            numbers[numbers[i] - 1], numbers[i] = numbers[i], numbers[numbers[i] - 1]  # swap into place

    # first index whose value is wrong reveals the missing positive
    for i in range(n):
        if numbers[i] != i + 1:
            return i + 1

    return n + 1  # all of 1..n are present


def main():
    print("Problem 4:")
    assert first_missing_positive([3, 4, -1, 1]) == 2, "assertion failed"
    assert first_missing_positive([1, 2, 0])      == 3, "assertion failed"
    assert first_missing_positive([1, 2, 3])      == 4, "assertion failed"
    assert first_missing_positive([7, 8, 9])      == 1, "assertion failed"
    print("All Tests Passed")
