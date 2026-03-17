local function hasArbitrage(rates)
    local n = #rates
    local dist = {}
    for i = 1, n do dist[i] = 0 end
    for _ = 1, n - 1 do
        for i = 1, n do
            for j = 1, n do
                if rates[i][j] ~= 0 then
                    local w = -math.log(rates[i][j])
                    if dist[i] + w < dist[j] then dist[j] = dist[i] + w end
                end
            end
        end
    end
    for i = 1, n do
        for j = 1, n do
            if rates[i][j] ~= 0 then
                local w = -math.log(rates[i][j])
                if dist[i] + w < dist[j] then return true end
            end
        end
    end
    return false
end

local function problem32()
    print("Problem 32:")
    local arb  = {{1,0.9,0.8},{1.2,1,0.9},{1.4,1.2,1}}
    local fair = {{1,2,4},{0.5,1,2},{0.25,0.5,1}}
    assert(hasArbitrage(arb)  == true,  "assertion failed")
    assert(hasArbitrage(fair) == false, "assertion failed")
    print("All Tests Passed")
end

return { problem32 = problem32 }
