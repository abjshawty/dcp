import random
from typing import List


def random_excluding(n: int, exclude: List[int]) -> int:
    excluded = set(exclude)
    valid = [i for i in range(n) if i not in excluded]
    return random.choice(valid)


def main():
    print("Problem 90:")
    for _ in range(100):
        assert random_excluding(5, [0,1,2,4]) == 3
    counts = {}
    for _ in range(1000):
        v = random_excluding(5, [2])
        counts[v] = counts.get(v, 0) + 1
    for k in [0,1,3,4]:
        assert counts.get(k, 0) > 100
    print("All Tests Passed")
