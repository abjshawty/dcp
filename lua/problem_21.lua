-- minRooms returns the minimum number of rooms to schedule all intervals.
-- Sort by start time; maintain a sorted list of end times (min-heap substitute).
-- This runs in O(n log n) time.
local function minRooms(intervals)
    if #intervals == 0 then return 0 end
    table.sort(intervals, function(a, b) return a[1] < b[1] end)
    local ends = {}  -- sorted list of end times

    for _, iv in ipairs(intervals) do
        local start, finish = iv[1], iv[2]
        if #ends > 0 and ends[1] <= start then
            table.remove(ends, 1)  -- reuse earliest-ending room
        end
        -- insert finish keeping ends sorted
        local pos = #ends + 1
        for i = 1, #ends do
            if ends[i] > finish then pos = i; break end
        end
        table.insert(ends, pos, finish)
    end
    return #ends
end

local function problem21()
    print("Problem 21:")
    assert(minRooms({{30,75},{0,50},{60,150}}) == 2, "assertion failed")
    assert(minRooms({{0,10},{10,20}})          == 1, "assertion failed")
    assert(minRooms({{0,10},{0,10}})           == 2, "assertion failed")
    print("All Tests Passed")
end

return { problem21 = problem21 }
