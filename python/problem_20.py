class ListNode:
    def __init__(self, val, next=None):
        self.val  = val
        self.next = next


def intersecting_node(head_a: ListNode, head_b: ListNode) -> ListNode:
    # intersecting_node finds the first shared node of two linked lists.
    # Advances two pointers; when one reaches the end it restarts at the
    # other list's head. They meet at the intersection after M+N steps.
    # This runs in O(M+N) time and O(1) space.
    a, b = head_a, head_b
    while a is not b:
        a = head_b if a is None else a.next
        b = head_a if b is None else b.next
    return a


def main():
    print("Problem 20:")
    shared = ListNode(8, ListNode(10))
    head_a = ListNode(3, ListNode(7, shared))
    head_b = ListNode(99, ListNode(1, shared))
    assert intersecting_node(head_a, head_b) is shared, "assertion failed"
    # no intersection
    assert intersecting_node(ListNode(1), ListNode(2)) is None, "assertion failed"
    print("All Tests Passed")
