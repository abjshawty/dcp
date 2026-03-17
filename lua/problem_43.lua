local function newMaxStack()
    return { data = {}, maxs = {} }
end

local function msPush(s, val)
    s.data[#s.data+1] = val
    if #s.maxs == 0 or val >= s.maxs[#s.maxs] then
        s.maxs[#s.maxs+1] = val
    else
        s.maxs[#s.maxs+1] = s.maxs[#s.maxs]
    end
end

local function msPop(s)
    if #s.data == 0 then return nil end
    local top = s.data[#s.data]
    s.data[#s.data] = nil
    s.maxs[#s.maxs] = nil
    return top
end

local function msMax(s)
    if #s.maxs == 0 then return nil end
    return s.maxs[#s.maxs]
end

local function problem43()
    print("Problem 43:")
    local s = newMaxStack()
    msPush(s, 1); msPush(s, 3); msPush(s, 2)
    assert(msMax(s) == 3, "assertion failed")
    assert(msPop(s) == 2, "assertion failed")
    assert(msMax(s) == 3, "assertion failed")
    assert(msPop(s) == 3, "assertion failed")
    assert(msMax(s) == 1, "assertion failed")
    assert(msPop(newMaxStack()) == nil, "assertion failed")
    print("All Tests Passed")
end

return { problem43 = problem43 }
