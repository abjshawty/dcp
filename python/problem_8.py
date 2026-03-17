class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def count_unival_subtrees(root: Node) -> int:
    # count_unival_subtrees counts subtrees where every node has the same value.
    # A leaf is always unival. An internal node is unival if both children are
    # unival and share the node's value. Uses a post-order DFS.
    def helper(node):
        # returns (is_unival, count)
        if node is None:
            return True, 0  # null node is trivially unival
        left_unival,  left_count  = helper(node.left)
        right_unival, right_count = helper(node.right)
        count = left_count + right_count

        is_unival = (
            left_unival and right_unival and
            (node.left  is None or node.left.val  == node.val) and
            (node.right is None or node.right.val == node.val)
        )
        if is_unival:
            count += 1
        return is_unival, count

    _, count = helper(root)
    return count


def main():
    print("Problem 8:")
    #       0
    #      / \
    #     1   0
    #        / \
    #       1   0
    #      / \
    #     1   1
    root = Node(0,
        Node(1),
        Node(0,
            Node(1, Node(1), Node(1)),
            Node(0)
        )
    )
    assert count_unival_subtrees(root) == 5, "assertion failed"
    print("All Tests Passed")
