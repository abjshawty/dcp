local function stepLife(alive)
    local counts = {}
    for k in pairs(alive) do
        local r, c = k:match("(-?%d+),(-?%d+)")
        r, c = tonumber(r), tonumber(c)
        for dr = -1, 1 do
            for dc = -1, 1 do
                if dr ~= 0 or dc ~= 0 then
                    local nk = (r+dr)..",".. (c+dc)
                    counts[nk] = (counts[nk] or 0) + 1
                end
            end
        end
    end
    local next = {}
    for p, cnt in pairs(counts) do
        if alive[p] and (cnt == 2 or cnt == 3) then next[p] = true
        elseif not alive[p] and cnt == 3        then next[p] = true end
    end
    return next
end

local function setSize(t) local n=0; for _ in pairs(t) do n=n+1 end; return n end

local function problem39()
    print("Problem 39:")
    local blinker = {["0,0"]=true, ["0,1"]=true, ["0,2"]=true}
    local s1 = stepLife(blinker)
    assert(setSize(s1) == 3, "assertion failed")
    local s2 = stepLife(s1)
    assert(setSize(s2) == 3, "assertion failed")
    assert(s2["0,0"] and s2["0,1"] and s2["0,2"], "assertion failed")
    print("All Tests Passed")
end

return { problem39 = problem39 }
