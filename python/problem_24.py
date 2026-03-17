class LockNode:
    def __init__(self, val, parent=None):
        self.val = val
        self.locked = False
        self.locked_desc_count = 0
        self.parent = parent
        self.left = None
        self.right = None

    def is_locked(self):
        return self.locked

    def _can_lock_or_unlock(self):
        if self.locked_desc_count > 0:
            return False
        p = self.parent
        while p:
            if p.locked:
                return False
            p = p.parent
        return True

    def lock(self):
        if self.locked or not self._can_lock_or_unlock():
            return False
        self.locked = True
        p = self.parent
        while p:
            p.locked_desc_count += 1
            p = p.parent
        return True

    def unlock(self):
        if not self.locked or not self._can_lock_or_unlock():
            return False
        self.locked = False
        p = self.parent
        while p:
            p.locked_desc_count -= 1
            p = p.parent
        return True


def main():
    print("Problem 24:")
    root = LockNode(1)
    root.left = LockNode(2, root)
    root.right = LockNode(3, root)
    root.left.left = LockNode(4, root.left)

    assert root.left.lock() == True
    assert root.left.is_locked() == True
    assert root.lock() == False              # has locked descendant
    assert root.left.left.lock() == False    # ancestor locked
    assert root.left.unlock() == True
    assert root.left.is_locked() == False
    assert root.lock() == True
    print("All Tests Passed")
