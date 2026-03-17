class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def serialize(root):
    # base case: represent null nodes with a sentinel
    if root is None:
        return '#'
    # pre-order: root, left subtree, right subtree
    return f'{root.val},{serialize(root.left)},{serialize(root.right)}'

def deserialize(s):
    # split the serialized string into a token stream
    tokens = iter(s.split(','))

    def build():
        val = next(tokens)
        if val == '#':  # sentinel marks a null node
            return None
        # reconstruct pre-order: node first, then left and right subtrees
        return Node(val, build(), build())

    return build()

def main():
    print("Problem 3:")
    node = Node('root', Node('left', Node('left.left')), Node('right'))
    assert deserialize(serialize(node)).left.left.val == 'left.left'
    print("All Tests Passed")
