from collections import OrderedDict
from typing import Optional


class LRUCache:
    def __init__(self, cap: int):
        self._cap = cap
        self._cache: OrderedDict = OrderedDict()

    def get(self, key: int) -> Optional[int]:
        if key not in self._cache:
            return None
        self._cache.move_to_end(key)
        return self._cache[key]

    def set(self, key: int, val: int) -> None:
        if key in self._cache:
            self._cache.move_to_end(key)
        self._cache[key] = val
        if len(self._cache) > self._cap:
            self._cache.popitem(last=False)


def main():
    print("Problem 52:")
    c = LRUCache(2)
    c.set(1, 1); c.set(2, 2)
    assert c.get(1) == 1
    c.set(3, 3)
    assert c.get(2) is None
    assert c.get(3) == 3
    print("All Tests Passed")
