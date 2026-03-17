-- OrderLog records the last N order IDs using a circular buffer.
-- record and getLast both run in O(1) time and O(N) space.

local OrderLog = {}
OrderLog.__index = OrderLog

local function newOrderLog(n)
    local buf = {}
    for i = 1, n do buf[i] = 0 end
    return setmetatable({ buf = buf, n = n, pos = 1 }, OrderLog)
end

function OrderLog:record(orderId)
    self.buf[self.pos] = orderId
    self.pos = (self.pos % self.n) + 1
end

-- getLast returns the i-th last element (i=1 is most recent).
function OrderLog:getLast(i)
    local idx = ((self.pos - 1 - i) % self.n) + 1
    return self.buf[idx]
end

local function problem16()
    print("Problem 16:")
    local log = newOrderLog(3)
    log:record(1); log:record(2); log:record(3)
    assert(log:getLast(1) == 3, "assertion failed")
    assert(log:getLast(2) == 2, "assertion failed")
    assert(log:getLast(3) == 1, "assertion failed")
    log:record(4)
    assert(log:getLast(1) == 4, "assertion failed")
    assert(log:getLast(2) == 3, "assertion failed")
    print("All Tests Passed")
end

return { problem16 = problem16 }
