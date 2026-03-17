import random


def rand7p() -> int:
    return random.randint(1, 7)


def rand5p() -> int:
    while True:
        v = rand7p()
        if v <= 5:
            return v


def main():
    print("Problem 71:")
    counts = [0] * 6
    for _ in range(50000):
        v = rand5p()
        assert 1 <= v <= 5
        counts[v] += 1
    for i in range(1, 6):
        assert 7000 < counts[i] < 13000
    print("All Tests Passed")
