from typing import Optional


class MaxStack:
    def __init__(self):
        self._data = []
        self._maxs = []

    def push(self, val: int) -> None:
        self._data.append(val)
        if not self._maxs or val >= self._maxs[-1]:
            self._maxs.append(val)
        else:
            self._maxs.append(self._maxs[-1])

    def pop(self) -> Optional[int]:
        if not self._data:
            return None
        self._maxs.pop()
        return self._data.pop()

    def max(self) -> Optional[int]:
        if not self._maxs:
            return None
        return self._maxs[-1]


def main():
    print("Problem 43:")
    s = MaxStack()
    s.push(1); s.push(3); s.push(2)
    assert s.max() == 3
    assert s.pop() == 2
    assert s.max() == 3
    assert s.pop() == 3
    assert s.max() == 1
    assert MaxStack().pop() is None
    print("All Tests Passed")
