-- intersectingNode finds the first shared node of two linked lists.
-- Advances two pointers; when one reaches the end it restarts at the
-- other list's head. They meet at the intersection after M+N steps.
-- This runs in O(M+N) time and O(1) space.

local function newListNode(val, next)
    return { val = val, next = next }
end

local function intersectingNode(headA, headB)
    local a, b = headA, headB
    while a ~= b do
        a = (a == nil) and headB or a.next
        b = (b == nil) and headA or b.next
    end
    return a
end

local function problem20()
    print("Problem 20:")
    local shared = newListNode(8, newListNode(10, nil))
    local headA  = newListNode(3, newListNode(7, shared))
    local headB  = newListNode(99, newListNode(1, shared))
    assert(intersectingNode(headA, headB) == shared, "assertion failed")
    -- no intersection
    assert(intersectingNode(newListNode(1, nil), newListNode(2, nil)) == nil, "assertion failed")
    print("All Tests Passed")
end

return { problem20 = problem20 }
