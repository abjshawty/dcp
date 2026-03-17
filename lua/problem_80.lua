local M = {}

local function deepest(node)
    if not node then return nil, 0 end
    local lv, ld = deepest(node.left)
    local rv, rd = deepest(node.right)
    if ld > rd then return lv, ld + 1
    elseif rd > ld then return rv, rd + 1
    else return node.val, 1 end
end

function M.deepest_node(root) return deepest(root) end

function M.problem80()
    print("Problem 80:")
    local root = {val='a',
        left  = {val='b', left={val='d',left=nil,right=nil}, right=nil},
        right = {val='c', left=nil, right=nil},
    }
    local v = M.deepest_node(root)
    assert(v == 'd')
    print("All Tests Passed")
end

return M
