class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def serialize(root):
    if root is None:
        return '#'
    return f'{root.val},{serialize(root.left)},{serialize(root.right)}'

def deserialize(s):
    pass

def main():
    node = Node('root', Node('left', Node('left.left')), Node('right'))
    assert deserialize(serialize(node)).left.left.val == 'left.left'

if __name__ == '__main__':
    # main()
    node = Node('root', Node('left', Node('left.left')), Node('right'))
    print(serialize(node))