from typing import Set, Tuple


def step(alive: Set[Tuple[int, int]]) -> Set[Tuple[int, int]]:
    neighbor_count = {}
    for (r, c) in alive:
        for dr in (-1, 0, 1):
            for dc in (-1, 0, 1):
                if dr == 0 and dc == 0:
                    continue
                p = (r + dr, c + dc)
                neighbor_count[p] = neighbor_count.get(p, 0) + 1
    next_alive = set()
    for p, cnt in neighbor_count.items():
        if p in alive and cnt in (2, 3):
            next_alive.add(p)
        elif p not in alive and cnt == 3:
            next_alive.add(p)
    return next_alive


def main():
    print("Problem 39:")
    blinker = {(0, 0), (0, 1), (0, 2)}
    s1 = step(blinker)
    assert len(s1) == 3
    s2 = step(s1)
    assert len(s2) == 3
    assert s2 == blinker
    print("All Tests Passed")
