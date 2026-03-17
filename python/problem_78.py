import heapq
from typing import List, Optional


class ListNode78:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __lt__(self, other): return self.val < other.val


def merge_k_lists(lists: List[Optional[ListNode78]]) -> Optional[ListNode78]:
    h = [node for node in lists if node]
    heapq.heapify(h)
    dummy = ListNode78()
    cur = dummy
    while h:
        node = heapq.heappop(h)
        cur.next = node
        cur = cur.next
        if node.next:
            heapq.heappush(h, node.next)
    return dummy.next


def from_list(vals):
    dummy = ListNode78()
    cur = dummy
    for v in vals: cur.next = ListNode78(v); cur = cur.next
    return dummy.next

def to_list(head):
    r = []
    while head: r.append(head.val); head = head.next
    return r


def main():
    print("Problem 78:")
    lists = [from_list([1,4,7]), from_list([2,5,8]), from_list([3,6,9])]
    assert to_list(merge_k_lists(lists)) == [1,2,3,4,5,6,7,8,9]
    print("All Tests Passed")
