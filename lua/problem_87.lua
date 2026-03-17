local M = {}

function M.validate_rules(rules)
    local x_lo, x_hi, y_lo, y_hi = {}, {}, {}, {}
    local function mx(t, k, v) t[k] = math.max(t[k] or -math.huge, v) end
    local function mn(t, k, v) t[k] = math.min(t[k] or  math.huge, v) end
    local function check()
        for k, v in pairs(x_lo) do if v >= (x_hi[k] or math.huge) then return false end end
        for k, v in pairs(y_lo) do if v >= (y_hi[k] or math.huge) then return false end end
        return true
    end
    for _, rule in ipairs(rules) do
        local parts = {}
        for w in rule:gmatch("%S+") do parts[#parts+1] = w end
        if #parts == 3 then
            local a, dir, b = parts[1], parts[2], parts[3]
            local eps = 1
            if     dir=='N'  then mx(y_lo, a, (y_lo[b] or 0) + eps)
            elseif dir=='S'  then mn(y_hi, a, (y_hi[b] or 0) - eps)
            elseif dir=='E'  then mx(x_lo, a, (x_lo[b] or 0) + eps)
            elseif dir=='W'  then mn(x_hi, a, (x_hi[b] or 0) - eps)
            elseif dir=='NE' then mx(y_lo,a,(y_lo[b] or 0)+eps); mx(x_lo,a,(x_lo[b] or 0)+eps)
            elseif dir=='NW' then mx(y_lo,a,(y_lo[b] or 0)+eps); mn(x_hi,a,(x_hi[b] or 0)-eps)
            elseif dir=='SE' then mn(y_hi,a,(y_hi[b] or 0)-eps); mx(x_lo,a,(x_lo[b] or 0)+eps)
            elseif dir=='SW' then mn(y_hi,a,(y_hi[b] or 0)-eps); mn(x_hi,a,(x_hi[b] or 0)-eps)
            end
            if not check() then return false end
        end
    end
    return true
end

function M.problem87()
    print("Problem 87:")
    assert(not M.validate_rules({"A N B", "B NE C", "C N A"}))
    assert(    M.validate_rules({"A NW B", "A N B"}))
    print("All Tests Passed")
end

return M
