local M = {}

local function eval_expr(node)
    if not node.left and not node.right then return tonumber(node.val) end
    local l = eval_expr(node.left)
    local r = eval_expr(node.right)
    if node.val == '+' then return l + r
    elseif node.val == '-' then return l - r
    elseif node.val == '*' then return l * r
    else return l / r end
end

function M.eval_expr(node) return eval_expr(node) end

function M.problem50()
    print("Problem 50:")
    local root = {val='*',
        left  = {val='+', left={val='3'}, right={val='2'}},
        right = {val='+', left={val='4'}, right={val='5'}},
    }
    assert(M.eval_expr(root) == 45)
    print("All Tests Passed")
end

return M
