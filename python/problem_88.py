def int_divide(a: int, b: int) -> int:
    quotient = 0
    while a >= b:
        a -= b
        quotient += 1
    return quotient


def main():
    print("Problem 88:")
    assert int_divide(10, 3)  == 3
    assert int_divide(7,  2)  == 3
    assert int_divide(100,10) == 10
    assert int_divide(1,  1)  == 1
    print("All Tests Passed")
