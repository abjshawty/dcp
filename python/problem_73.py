from typing import Optional


class ListNode73:
    def __init__(self, val=0, next=None):
        self.val = val; self.next = next


def reverse_list(head: Optional[ListNode73]) -> Optional[ListNode73]:
    prev = None
    curr = head
    while curr:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt
    return prev


def to_list(head):
    r = []
    while head: r.append(head.val); head = head.next
    return r


def from_list(vals):
    dummy = ListNode73()
    cur = dummy
    for v in vals: cur.next = ListNode73(v); cur = cur.next
    return dummy.next


def main():
    print("Problem 73:")
    assert to_list(reverse_list(from_list([1,2,3,4,5]))) == [5,4,3,2,1]
    assert to_list(reverse_list(from_list([1])))          == [1]
    assert reverse_list(None) is None
    print("All Tests Passed")
