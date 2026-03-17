def nth_perfect_number(n: int) -> int:
    count, num = 0, 0
    while count < n:
        num += 1
        if sum(int(d) for d in str(num)) == 10:
            count += 1
    return num


def main():
    print("Problem 70:")
    assert nth_perfect_number(1) == 19
    assert nth_perfect_number(2) == 28
    assert nth_perfect_number(3) == 37
    print("All Tests Passed")
