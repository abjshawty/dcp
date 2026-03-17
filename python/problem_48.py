from typing import List, Optional


class TreeNode48:
    def __init__(self, val, left=None, right=None):
        self.val = val; self.left = left; self.right = right


def build_tree(preorder: List[str], inorder: List[str]) -> Optional[TreeNode48]:
    if not preorder:
        return None
    root = TreeNode48(preorder[0])
    idx = inorder.index(preorder[0])
    root.left  = build_tree(preorder[1:1+idx], inorder[:idx])
    root.right = build_tree(preorder[1+idx:],  inorder[idx+1:])
    return root


def inorder_traversal(root: Optional[TreeNode48]) -> List[str]:
    if root is None:
        return []
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right)


def main():
    print("Problem 48:")
    pre = ["a","b","d","e","c","f","g"]
    ino = ["d","b","e","a","f","c","g"]
    root = build_tree(pre, ino)
    assert inorder_traversal(root) == ino
    print("All Tests Passed")
