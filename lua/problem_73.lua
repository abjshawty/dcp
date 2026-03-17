local M = {}

function M.reverse_list(head)
    local prev = nil
    local curr = head
    while curr do
        local nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt
    end
    return prev
end

local function from_list(vals)
    local dummy = {next=nil}
    local cur = dummy
    for _, v in ipairs(vals) do
        cur.next = {val=v, next=nil}; cur = cur.next
    end
    return dummy.next
end

local function to_list(head)
    local r = {}
    while head do r[#r+1] = head.val; head = head.next end
    return r
end

function M.problem73()
    print("Problem 73:")
    local result = to_list(M.reverse_list(from_list({1,2,3,4,5})))
    local exp = {5,4,3,2,1}
    assert(#result == #exp)
    for i = 1, #exp do assert(result[i] == exp[i]) end
    assert(M.reverse_list(nil) == nil)
    print("All Tests Passed")
end

return M
