import random
from typing import List


def shuffle(deck: List[int]) -> None:
    for i in range(len(deck) - 1, 0, -1):
        j = random.randint(0, i)
        deck[i], deck[j] = deck[j], deck[i]


def main():
    print("Problem 51:")
    deck = list(range(52))
    shuffle(deck)
    assert sorted(deck) == list(range(52))
    print("All Tests Passed")
