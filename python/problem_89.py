from typing import Optional


class TreeNode89:
    def __init__(self, val=0, left=None, right=None):
        self.val = val; self.left = left; self.right = right


def is_valid_bst(root: Optional[TreeNode89], lo=float('-inf'), hi=float('inf')) -> bool:
    if root is None:
        return True
    if not (lo < root.val < hi):
        return False
    return is_valid_bst(root.left, lo, root.val) and is_valid_bst(root.right, root.val, hi)


def main():
    print("Problem 89:")
    valid = TreeNode89(5,
        TreeNode89(3, TreeNode89(2), TreeNode89(4)),
        TreeNode89(7, TreeNode89(6), TreeNode89(8))
    )
    invalid = TreeNode89(5, TreeNode89(3), TreeNode89(4))
    assert     is_valid_bst(valid)
    assert not is_valid_bst(invalid)
    print("All Tests Passed")
