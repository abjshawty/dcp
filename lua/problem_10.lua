-- schedule calls f after n milliseconds.
-- In Lua (no built-in async), we simulate with os.clock busy-wait for testing.
local function schedule(f, n)
    local start = os.clock()
    while (os.clock() - start) * 1000 < n do end
    f()
end

local function problem10()
    print("Problem 10:")
    local fired = false
    schedule(function() fired = true end, 5)  -- use 5ms to keep tests fast
    assert(fired, "assertion failed")
    print("All Tests Passed")
end

return { problem10 = problem10 }
