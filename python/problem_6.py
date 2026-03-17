# xorNode stores a value and the XOR of its neighbours' indices.
# A list of nodes backed by a Python list simulates pointer arithmetic.

class XorLinkedList:
    # XorLinkedList is an XOR doubly-linked list backed by a Python list.
    # Using list indices as stand-ins for memory addresses.
    def __init__(self):
        self._nodes = []  # list of (val, both) tuples; index = "address"
        self._head = -1
        self._tail = -1

    def add(self, val: int) -> None:
        # append element to the end of the list
        idx = len(self._nodes)
        prev = self._tail
        self._nodes.append([val, prev ^ -1])  # both = prev XOR null(-1)
        if self._tail != -1:
            # update old tail: replace null(-1) with new index
            old_val, old_both = self._nodes[self._tail]
            self._nodes[self._tail][1] = old_both ^ (-1 ^ idx)
        self._tail = idx
        if self._head == -1:
            self._head = idx

    def get(self, index: int) -> int:
        # traverse to the index-th node (0-based)
        prev, curr = -1, self._head
        for _ in range(index):
            nxt = prev ^ self._nodes[curr][1]  # XOR out prev to get next
            prev, curr = curr, nxt
        return self._nodes[curr][0]


def main():
    print("Problem 6:")
    lst = XorLinkedList()
    for v in [1, 2, 3, 4]:
        lst.add(v)
    assert lst.get(0) == 1, "assertion failed"
    assert lst.get(1) == 2, "assertion failed"
    assert lst.get(2) == 3, "assertion failed"
    assert lst.get(3) == 4, "assertion failed"
    print("All Tests Passed")
