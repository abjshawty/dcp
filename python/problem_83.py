from typing import Optional, List


class TreeNode83:
    def __init__(self, val=0, left=None, right=None):
        self.val = val; self.left = left; self.right = right


def invert_tree(root: Optional[TreeNode83]) -> Optional[TreeNode83]:
    if root is None:
        return None
    root.left, root.right = invert_tree(root.right), invert_tree(root.left)
    return root


def inorder(root) -> List[int]:
    if root is None: return []
    return inorder(root.left) + [root.val] + inorder(root.right)


def main():
    print("Problem 83:")
    root = TreeNode83(4,
        TreeNode83(2, TreeNode83(1), TreeNode83(3)),
        TreeNode83(7, TreeNode83(6), TreeNode83(9))
    )
    assert inorder(invert_tree(root)) == [9, 7, 6, 4, 3, 2, 1]
    print("All Tests Passed")
