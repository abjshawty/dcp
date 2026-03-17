local M = {}

local function build_tree(pre, ino)
    if #pre == 0 then return nil end
    local root_val = pre[1]
    local idx = 0
    for i, v in ipairs(ino) do if v == root_val then idx = i; break end end
    local left_in  = {table.unpack(ino, 1, idx - 1)}
    local right_in = {table.unpack(ino, idx + 1)}
    local left_pre  = {table.unpack(pre, 2, 1 + idx - 1)}
    local right_pre = {table.unpack(pre, 1 + idx)}
    return {val = root_val, left = build_tree(left_pre, left_in), right = build_tree(right_pre, right_in)}
end

local function inorder(node, out)
    if not node then return end
    inorder(node.left, out)
    out[#out+1] = node.val
    inorder(node.right, out)
end

function M.build_tree(pre, ino) return build_tree(pre, ino) end

function M.problem48()
    print("Problem 48:")
    local pre = {"a","b","d","e","c","f","g"}
    local ino = {"d","b","e","a","f","c","g"}
    local root = M.build_tree(pre, ino)
    local out = {}
    inorder(root, out)
    assert(#out == #ino)
    for i = 1, #out do assert(out[i] == ino[i]) end
    print("All Tests Passed")
end

return M
