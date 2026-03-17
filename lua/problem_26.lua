local function slList(...)
    local dummy = { val = 0, next = nil }
    local cur = dummy
    for _, v in ipairs({...}) do
        cur.next = { val = v, next = nil }
        cur = cur.next
    end
    return dummy.next
end

local function slToTable(head)
    local out = {}
    while head do out[#out + 1] = head.val; head = head.next end
    return out
end

local function removeKthLast(head, k)
    local dummy = { val = 0, next = head }
    local fast, slow = dummy, dummy
    for _ = 1, k + 1 do fast = fast.next end
    while fast do fast = fast.next; slow = slow.next end
    slow.next = slow.next.next
    return dummy.next
end

local function tableEq(a, b)
    if #a ~= #b then return false end
    for i = 1, #a do if a[i] ~= b[i] then return false end end
    return true
end

local function problem26()
    print("Problem 26:")
    assert(tableEq(slToTable(removeKthLast(slList(1,2,3,4,5), 2)), {1,2,3,5}), "assertion failed")
    assert(tableEq(slToTable(removeKthLast(slList(1,2,3),     1)), {1,2}),     "assertion failed")
    assert(tableEq(slToTable(removeKthLast(slList(1,2),       2)), {2}),        "assertion failed")
    print("All Tests Passed")
end

return { problem26 = problem26 }
