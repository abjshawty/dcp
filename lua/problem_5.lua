-- cons constructs a pair encoded as a closure. car and cdr extract the first
-- and second elements by passing selector functions into the pair.
local function cons(a, b)
    return function(f) return f(a, b) end
end

-- car returns the first element of a pair.
local function car(pair)
    return pair(function(a, _) return a end)
end

-- cdr returns the second element of a pair.
local function cdr(pair)
    return pair(function(_, b) return b end)
end

local function problem5()
    print("Problem 5:")
    assert(car(cons(3, 4))  == 3,  "assertion failed")
    assert(cdr(cons(3, 4))  == 4,  "assertion failed")
    assert(car(cons(0, -1)) == 0,  "assertion failed")
    assert(cdr(cons(0, -1)) == -1, "assertion failed")
    print("All Tests Passed")
end

return { problem5 = problem5 }
