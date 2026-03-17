local function newLockNode(val, parent)
    return { val = val, locked = false, lockedDescCount = 0, parent = parent, left = nil, right = nil }
end

local function isLocked(node) return node.locked end

local function canLockOrUnlock(node)
    if node.lockedDescCount > 0 then return false end
    local p = node.parent
    while p do
        if p.locked then return false end
        p = p.parent
    end
    return true
end

local function lockNode(node)
    if node.locked or not canLockOrUnlock(node) then return false end
    node.locked = true
    local p = node.parent
    while p do p.lockedDescCount = p.lockedDescCount + 1; p = p.parent end
    return true
end

local function unlockNode(node)
    if not node.locked or not canLockOrUnlock(node) then return false end
    node.locked = false
    local p = node.parent
    while p do p.lockedDescCount = p.lockedDescCount - 1; p = p.parent end
    return true
end

local function problem24()
    print("Problem 24:")
    local root = newLockNode(1, nil)
    root.left       = newLockNode(2, root)
    root.right      = newLockNode(3, root)
    root.left.left  = newLockNode(4, root.left)

    assert(lockNode(root.left)       == true,  "assertion failed")
    assert(isLocked(root.left)       == true,  "assertion failed")
    assert(lockNode(root)            == false, "assertion failed") -- locked descendant
    assert(lockNode(root.left.left)  == false, "assertion failed") -- ancestor locked
    assert(unlockNode(root.left)     == true,  "assertion failed")
    assert(isLocked(root.left)       == false, "assertion failed")
    assert(lockNode(root)            == true,  "assertion failed")
    print("All Tests Passed")
end

return { problem24 = problem24 }
