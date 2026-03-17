class BSTNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def second_largest(root: BSTNode) -> int:
    parent, curr = None, root
    while curr.right:
        parent = curr
        curr = curr.right
    if curr.left:
        node = curr.left
        while node.right:
            node = node.right
        return node.val
    return parent.val


def main():
    print("Problem 36:")
    root = BSTNode(5,
        BSTNode(3, BSTNode(2), BSTNode(4)),
        BSTNode(7, BSTNode(6), BSTNode(8))
    )
    assert second_largest(root) == 7
    root2 = BSTNode(3, None, BSTNode(4, None, BSTNode(5)))
    assert second_largest(root2) == 4
    root3 = BSTNode(5, BSTNode(3, None, BSTNode(4)), None)
    assert second_largest(root3) == 4
    print("All Tests Passed")
