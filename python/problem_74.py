def count_in_mult_table(n: int, x: int) -> int:
    count = 0
    for i in range(1, n + 1):
        if x % i == 0 and x // i <= n:
            count += 1
    return count


def main():
    print("Problem 74:")
    assert count_in_mult_table(6, 12) == 4
    assert count_in_mult_table(3, 6)  == 2
    assert count_in_mult_table(1, 1)  == 1
    print("All Tests Passed")
