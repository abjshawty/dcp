-- XorLinkedList is an XOR doubly-linked list backed by a Lua table.
-- Table indices (1-based) serve as stand-in memory addresses; -1 is null.

local XorLinkedList = {}
XorLinkedList.__index = XorLinkedList

local function newXorLinkedList()
    return setmetatable({ nodes = {}, head = -1, tail = -1 }, XorLinkedList)
end

-- add appends an element to the end of the list.
function XorLinkedList:add(val)
    local idx = #self.nodes + 1   -- 1-based index
    local prev = self.tail
    self.nodes[idx] = { val = val, both = prev ~ -1 }  -- both = prev XOR null(-1)
    if self.tail ~= -1 then
        -- update old tail: replace null(-1) with new index
        self.nodes[self.tail].both = self.nodes[self.tail].both ~ (-1 ~ idx)
    end
    self.tail = idx
    if self.head == -1 then self.head = idx end
end

-- get returns the value at the given 0-based index.
function XorLinkedList:get(index)
    local prev, curr = -1, self.head
    for _ = 1, index do
        local nxt = prev ~ self.nodes[curr].both  -- XOR out prev to get next
        prev, curr = curr, nxt
    end
    return self.nodes[curr].val
end

local function problem6()
    print("Problem 6:")
    local lst = newXorLinkedList()
    for _, v in ipairs({1, 2, 3, 4}) do lst:add(v) end
    assert(lst:get(0) == 1, "assertion failed")
    assert(lst:get(1) == 2, "assertion failed")
    assert(lst:get(2) == 3, "assertion failed")
    assert(lst:get(3) == 4, "assertion failed")
    print("All Tests Passed")
end

return { problem6 = problem6 }
