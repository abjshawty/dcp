import random


def rand5() -> int:
    return random.randint(1, 5)


def rand7() -> int:
    while True:
        n = (rand5() - 1) * 5 + (rand5() - 1)
        if n < 21:
            return n % 7 + 1


def main():
    print("Problem 45:")
    counts = [0] * 8
    for _ in range(70000):
        v = rand7()
        assert 1 <= v <= 7
        counts[v] += 1
    for i in range(1, 8):
        assert 7000 < counts[i] < 13000, f"distribution off: {counts}"
    print("All Tests Passed")
