local M = {}

function M.merge_k_lists(lists)
    local function node_val(n) return n and n.val or math.huge end
    local dummy = {next=nil}; local cur = dummy
    while true do
        local min_val, min_idx = math.huge, nil
        for i, head in ipairs(lists) do
            if head and head.val < min_val then min_val = head.val; min_idx = i end
        end
        if not min_idx then break end
        cur.next = lists[min_idx]; cur = cur.next; lists[min_idx] = lists[min_idx].next
    end
    return dummy.next
end

local function from_list(vals)
    local d = {next=nil}; local c = d
    for _, v in ipairs(vals) do c.next={val=v,next=nil}; c=c.next end
    return d.next
end

local function to_list(h)
    local r = {}; while h do r[#r+1]=h.val; h=h.next end; return r
end

function M.problem78()
    print("Problem 78:")
    local lists = {from_list({1,4,7}), from_list({2,5,8}), from_list({3,6,9})}
    local got = to_list(M.merge_k_lists(lists))
    local exp = {1,2,3,4,5,6,7,8,9}
    assert(#got == #exp)
    for i = 1, #exp do assert(got[i] == exp[i]) end
    print("All Tests Passed")
end

return M
