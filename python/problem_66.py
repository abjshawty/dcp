import random


def toss_biased() -> int:
    return 1 if random.random() < 0.7 else 0


def unbiased_coin() -> int:
    while True:
        a, b = toss_biased(), toss_biased()
        if a == 0 and b == 1: return 0
        if a == 1 and b == 0: return 1


def main():
    print("Problem 66:")
    counts = [0, 0]
    for _ in range(10000):
        counts[unbiased_coin()] += 1
    assert 4000 < counts[0] < 6000 and 4000 < counts[1] < 6000
    print("All Tests Passed")
