class ExprNode:
    def __init__(self, val, left=None, right=None):
        self.val = val; self.left = left; self.right = right


def eval_expr(root: ExprNode) -> float:
    if root.left is None and root.right is None:
        return float(root.val)
    l = eval_expr(root.left)
    r = eval_expr(root.right)
    if root.val == '+': return l + r
    if root.val == '-': return l - r
    if root.val == '*': return l * r
    return l / r


def main():
    print("Problem 50:")
    root = ExprNode('*',
        ExprNode('+', ExprNode('3'), ExprNode('2')),
        ExprNode('+', ExprNode('4'), ExprNode('5')),
    )
    assert eval_expr(root) == 45.0
    print("All Tests Passed")
