local M = {}

function M.new_stack_queue()
    local q = {inbox = {}, outbox = {}}
    function q:enqueue(v) self.inbox[#self.inbox+1] = v end
    function q:dequeue()
        if #self.outbox == 0 then
            while #self.inbox > 0 do
                self.outbox[#self.outbox+1] = table.remove(self.inbox)
            end
        end
        if #self.outbox == 0 then return nil end
        return table.remove(self.outbox)
    end
    return q
end

function M.problem53()
    print("Problem 53:")
    local q = M.new_stack_queue()
    q:enqueue(1); q:enqueue(2); q:enqueue(3)
    assert(q:dequeue() == 1)
    assert(q:dequeue() == 2)
    q:enqueue(4)
    assert(q:dequeue() == 3)
    assert(q:dequeue() == 4)
    assert(q:dequeue() == nil)
    print("All Tests Passed")
end

return M
