from collections import defaultdict, OrderedDict
from typing import Optional


class LFUCache:
    def __init__(self, cap: int):
        self._cap = cap
        self._keys = {}
        self._freq_buckets: dict = defaultdict(OrderedDict)
        self._min_freq = 0

    def _touch(self, key: int):
        val, freq = self._keys[key]
        del self._freq_buckets[freq][key]
        if not self._freq_buckets[freq]:
            del self._freq_buckets[freq]
            if self._min_freq == freq:
                self._min_freq += 1
        freq += 1
        self._keys[key] = (val, freq)
        self._freq_buckets[freq][key] = None

    def get(self, key: int) -> Optional[int]:
        if key not in self._keys:
            return None
        self._touch(key)
        return self._keys[key][0]

    def set(self, key: int, val: int) -> None:
        if self._cap == 0:
            return
        if key in self._keys:
            self._keys[key] = (val, self._keys[key][1])
            self._touch(key)
            return
        if len(self._keys) == self._cap:
            evict, _ = self._freq_buckets[self._min_freq].popitem(last=False)
            del self._keys[evict]
        self._keys[key] = (val, 1)
        self._freq_buckets[1][key] = None
        self._min_freq = 1


def main():
    print("Problem 67:")
    c = LFUCache(2)
    c.set(1,1); c.set(2,2)
    assert c.get(1) == 1
    c.set(3,3)
    assert c.get(2) is None
    assert c.get(3) == 3
    print("All Tests Passed")
