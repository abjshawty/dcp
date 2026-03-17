def select_by_bit(x: int, y: int, b: int) -> int:
    return x * b + y * (1 - b)


def main():
    print("Problem 85:")
    assert select_by_bit(10, 20, 1) == 10
    assert select_by_bit(10, 20, 0) == 20
    assert select_by_bit(5,  7,  1) == 5
    print("All Tests Passed")
