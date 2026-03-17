-- countUnivalSubtrees counts subtrees where every node has the same value.
-- A leaf is always unival. An internal node is unival if both children are
-- unival and share the node's value. Uses post-order DFS.

local function newNode(val, left, right)
    return { val = val, left = left, right = right }
end

-- helper returns is_unival, count
local function helper(node)
    if node == nil then return true, 0 end
    local leftUnival,  leftCount  = helper(node.left)
    local rightUnival, rightCount = helper(node.right)
    local count = leftCount + rightCount

    local isUnival = leftUnival and rightUnival
        and (node.left  == nil or node.left.val  == node.val)
        and (node.right == nil or node.right.val == node.val)

    if isUnival then count = count + 1 end
    return isUnival, count
end

local function countUnivalSubtrees(root)
    local _, count = helper(root)
    return count
end

local function problem8()
    print("Problem 8:")
    --       0
    --      / \
    --     1   0
    --        / \
    --       1   0
    --      / \
    --     1   1
    local root = newNode(0,
        newNode(1),
        newNode(0,
            newNode(1, newNode(1), newNode(1)),
            newNode(0)
        )
    )
    assert(countUnivalSubtrees(root) == 5, "assertion failed")
    print("All Tests Passed")
end

return { problem8 = problem8 }
