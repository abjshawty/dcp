local M = {}

local function is_valid_bst(node, lo, hi)
    if not node then return true end
    if node.val <= lo or node.val >= hi then return false end
    return is_valid_bst(node.left, lo, node.val) and is_valid_bst(node.right, node.val, hi)
end

function M.is_valid_bst(root) return is_valid_bst(root, -math.huge, math.huge) end

function M.problem89()
    print("Problem 89:")
    local valid = {val=5,
        left  = {val=3, left={val=2,left=nil,right=nil}, right={val=4,left=nil,right=nil}},
        right = {val=7, left={val=6,left=nil,right=nil}, right={val=8,left=nil,right=nil}},
    }
    local invalid = {val=5, left={val=3,left=nil,right=nil}, right={val=4,left=nil,right=nil}}
    assert(    M.is_valid_bst(valid))
    assert(not M.is_valid_bst(invalid))
    print("All Tests Passed")
end

return M
