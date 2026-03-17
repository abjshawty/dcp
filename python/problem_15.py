import random


def reservoir_sample(stream: list, seed: int = 42) -> object:
    # reservoir_sample picks one element uniformly at random from a stream.
    # Keeps the first element, then for each subsequent element i (1-indexed)
    # replaces with probability 1/(i+1).
    # This runs in O(n) time and O(1) space.
    rng = random.Random(seed)
    result = stream[0]
    for i in range(1, len(stream)):
        if rng.randint(0, i) == 0:  # probability 1/(i+1)
            result = stream[i]
    return result


def main():
    print("Problem 15:")
    stream = list(range(1, 11))
    counts: dict[int, int] = {}
    trials = 100_000
    for seed in range(trials):
        v = reservoir_sample(stream, seed=seed)
        counts[v] = counts.get(v, 0) + 1
    for v in stream:
        freq = counts.get(v, 0) / trials
        assert 0.08 <= freq <= 0.12, f"assertion failed: element {v} frequency {freq:.4f}"
    print("All Tests Passed")
