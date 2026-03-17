-- estimatePi estimates π using Monte Carlo simulation.
-- Random points thrown at a unit square; those inside the inscribed
-- quarter-circle (x²+y² ≤ 1) approximate π/4.
local function estimatePi(samples, seed)
    math.randomseed(seed or 42)
    local inside = 0
    for _ = 1, samples do
        local x = math.random()
        local y = math.random()
        if x*x + y*y <= 1.0 then inside = inside + 1 end
    end
    return 4.0 * inside / samples
end

local function problem14()
    print("Problem 14:")
    local pi = estimatePi(1000000, 42)
    assert(math.abs(pi - math.pi) < 0.01, string.format("assertion failed: got %f", pi))
    print("All Tests Passed")
end

return { problem14 = problem14 }
