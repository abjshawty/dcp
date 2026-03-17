class SLNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next


def sl_list(*vals):
    dummy = SLNode(0)
    cur = dummy
    for v in vals:
        cur.next = SLNode(v)
        cur = cur.next
    return dummy.next


def sl_to_list(head):
    out = []
    while head:
        out.append(head.val)
        head = head.next
    return out


def remove_kth_last(head, k):
    dummy = SLNode(0, head)
    fast = slow = dummy
    for _ in range(k + 1):
        fast = fast.next
    while fast:
        fast = fast.next
        slow = slow.next
    slow.next = slow.next.next
    return dummy.next


def main():
    print("Problem 26:")
    assert sl_to_list(remove_kth_last(sl_list(1, 2, 3, 4, 5), 2)) == [1, 2, 3, 5]
    assert sl_to_list(remove_kth_last(sl_list(1, 2, 3), 1))       == [1, 2]
    assert sl_to_list(remove_kth_last(sl_list(1, 2), 2))           == [2]
    print("All Tests Passed")
