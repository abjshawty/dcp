from typing import Optional, Tuple


class TreeNode80:
    def __init__(self, val, left=None, right=None):
        self.val = val; self.left = left; self.right = right


def deepest_node(root: Optional[TreeNode80]) -> Tuple[str, int]:
    if root is None:
        return ('', 0)
    lv, ld = deepest_node(root.left)
    rv, rd = deepest_node(root.right)
    if ld > rd: return (lv, ld + 1)
    if rd > ld: return (rv, rd + 1)
    return (root.val, 1)


def main():
    print("Problem 80:")
    root = TreeNode80('a',
        TreeNode80('b', TreeNode80('d')),
        TreeNode80('c')
    )
    assert deepest_node(root)[0] == 'd'
    print("All Tests Passed")
