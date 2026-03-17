local function newBST(val, left, right)
    return { val = val, left = left, right = right }
end

local function secondLargest(root)
    local parent, curr = nil, root
    while curr.right do
        parent = curr; curr = curr.right
    end
    if curr.left then
        local node = curr.left
        while node.right do node = node.right end
        return node.val
    end
    return parent.val
end

local function problem36()
    print("Problem 36:")
    local root = newBST(5,
        newBST(3, newBST(2,nil,nil), newBST(4,nil,nil)),
        newBST(7, newBST(6,nil,nil), newBST(8,nil,nil))
    )
    assert(secondLargest(root) == 7, "assertion failed")
    local root2 = newBST(3, nil, newBST(4, nil, newBST(5,nil,nil)))
    assert(secondLargest(root2) == 4, "assertion failed")
    local root3 = newBST(5, newBST(3, nil, newBST(4,nil,nil)), nil)
    assert(secondLargest(root3) == 4, "assertion failed")
    print("All Tests Passed")
end

return { problem36 = problem36 }
