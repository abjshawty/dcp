-- reservoirSample picks one element uniformly at random from a stream.
-- Keeps the first element, then for each subsequent element i replaces
-- with probability 1/(i+1). This runs in O(n) time and O(1) space.
local function reservoirSample(stream, seed)
    math.randomseed(seed or 42)
    local result = stream[1]
    for i = 2, #stream do
        if math.random(i) == 1 then  -- probability 1/i
            result = stream[i]
        end
    end
    return result
end

local function problem15()
    print("Problem 15:")
    local stream = {1,2,3,4,5,6,7,8,9,10}
    local counts = {}
    local trials = 100000
    for seed = 0, trials - 1 do
        local v = reservoirSample(stream, seed)
        counts[v] = (counts[v] or 0) + 1
    end
    for _, v in ipairs(stream) do
        local freq = (counts[v] or 0) / trials
        assert(freq >= 0.07 and freq <= 0.13,
            string.format("assertion failed: element %d frequency %.4f", v, freq))
    end
    print("All Tests Passed")
end

return { problem15 = problem15 }
