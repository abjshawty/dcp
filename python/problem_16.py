class OrderLog:
    # OrderLog records the last N order IDs using a circular buffer.
    # record and get_last both run in O(1) time and O(N) space.
    def __init__(self, n: int):
        self._buf = [0] * n
        self._n = n
        self._pos = 0

    def record(self, order_id: int) -> None:
        # adds the order_id to the log
        self._buf[self._pos] = order_id
        self._pos = (self._pos + 1) % self._n

    def get_last(self, i: int) -> int:
        # returns the i-th last element (i=1 is most recent)
        return self._buf[(self._pos - i) % self._n]


def main():
    print("Problem 16:")
    log = OrderLog(3)
    log.record(1)
    log.record(2)
    log.record(3)
    assert log.get_last(1) == 3, "assertion failed"
    assert log.get_last(2) == 2, "assertion failed"
    assert log.get_last(3) == 1, "assertion failed"
    log.record(4)
    assert log.get_last(1) == 4, "assertion failed"
    assert log.get_last(2) == 3, "assertion failed"
    print("All Tests Passed")
