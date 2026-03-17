-- Node constructor for a binary tree node.
local function Node(val, left, right)
    return {val = val, left = left, right = right}
end

-- serialize encodes a binary tree into a comma-separated string using
-- pre-order traversal. Null nodes are represented with the sentinel "#".
local function serialize(root)
    if root == nil then
        return "#"
    end
    -- pre-order: root, left subtree, right subtree
    return root.val .. "," .. serialize(root.left) .. "," .. serialize(root.right)
end

-- deserialize reconstructs a binary tree from a string produced by serialize.
-- It consumes tokens from a shared iterator, mirroring the pre-order encoding.
local function deserialize(s)
    local tokens = {}
    for tok in s:gmatch("[^,]+") do
        tokens[#tokens + 1] = tok
    end
    local idx = 0

    local function build()
        idx = idx + 1
        local val = tokens[idx]
        if val == "#" then -- sentinel marks a null node
            return nil
        end
        -- reconstruct pre-order: node first, then left and right subtrees
        local left  = build()
        local right = build()
        return Node(val, left, right)
    end

    return build()
end

local function problem3()
    print("Problem 3:")
    local node = Node("root",
        Node("left", Node("left.left", nil, nil), nil),
        Node("right", nil, nil))
    local result = deserialize(serialize(node))
    assert(result.left.left.val == "left.left", "assertion failed")
    print("All Tests Passed")
end

return { Node = Node, serialize = serialize, deserialize = deserialize, problem3 = problem3 }
