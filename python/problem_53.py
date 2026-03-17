from typing import Optional


class StackQueue:
    def __init__(self):
        self._inbox = []
        self._outbox = []

    def enqueue(self, val: int) -> None:
        self._inbox.append(val)

    def dequeue(self) -> Optional[int]:
        if not self._outbox:
            while self._inbox:
                self._outbox.append(self._inbox.pop())
        return self._outbox.pop() if self._outbox else None


def main():
    print("Problem 53:")
    q = StackQueue()
    q.enqueue(1); q.enqueue(2); q.enqueue(3)
    assert q.dequeue() == 1
    assert q.dequeue() == 2
    q.enqueue(4)
    assert q.dequeue() == 3
    assert q.dequeue() == 4
    assert q.dequeue() is None
    print("All Tests Passed")
