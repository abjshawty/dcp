import math
import random


def estimate_pi(samples: int, seed: int = 42) -> float:
    # estimate_pi estimates π using Monte Carlo simulation.
    # Random points thrown at a unit square; those inside the inscribed
    # quarter-circle (x²+y² ≤ 1) approximate π/4.
    rng = random.Random(seed)
    inside = sum(
        1 for _ in range(samples)
        if rng.random() ** 2 + rng.random() ** 2 <= 1.0
    )
    return 4.0 * inside / samples


def main():
    print("Problem 14:")
    pi = estimate_pi(1_000_000)
    assert abs(pi - math.pi) < 0.01, f"assertion failed: got {pi}"
    print("All Tests Passed")
