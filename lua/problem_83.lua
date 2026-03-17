local M = {}

function M.invert_tree(root)
    if not root then return nil end
    root.left, root.right = M.invert_tree(root.right), M.invert_tree(root.left)
    return root
end

local function inorder(node, out)
    if not node then return end
    inorder(node.left, out); out[#out+1] = node.val; inorder(node.right, out)
end

function M.problem83()
    print("Problem 83:")
    local root = {val=4,
        left  = {val=2, left={val=1,left=nil,right=nil}, right={val=3,left=nil,right=nil}},
        right = {val=7, left={val=6,left=nil,right=nil}, right={val=9,left=nil,right=nil}},
    }
    M.invert_tree(root)
    local out = {}; inorder(root, out)
    local exp = {9,7,6,4,3,2,1}
    assert(#out == #exp)
    for i = 1, #exp do assert(out[i] == exp[i]) end
    print("All Tests Passed")
end

return M
