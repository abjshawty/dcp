def fast_pow(x: int, y: int) -> int:
    if y == 0: return 1
    if y < 0:  return 0
    half = fast_pow(x, y // 2)
    return half * half if y % 2 == 0 else half * half * x


def main():
    print("Problem 61:")
    assert fast_pow(2, 10) == 1024
    assert fast_pow(3, 0)  == 1
    assert fast_pow(5, 3)  == 125
    print("All Tests Passed")
