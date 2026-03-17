local M = {}

function M.new_lfu_cache(cap)
    local c = {cap=cap, keys={}, freqs={}, min_freq=0}

    local function touch(key)
        local e = c.keys[key]
        local bucket = c.freqs[e.freq]
        for i, k in ipairs(bucket) do
            if k == key then table.remove(bucket, i); break end
        end
        if #bucket == 0 then
            c.freqs[e.freq] = nil
            if c.min_freq == e.freq then c.min_freq = e.freq + 1 end
        end
        e.freq = e.freq + 1
        if not c.freqs[e.freq] then c.freqs[e.freq] = {} end
        table.insert(c.freqs[e.freq], key)
    end

    function c:get(key)
        if not self.keys[key] then return nil end
        touch(key)
        return self.keys[key].val
    end

    function c:set(key, val)
        if self.cap == 0 then return end
        if self.keys[key] then
            self.keys[key].val = val; touch(key); return
        end
        local size = 0; for _ in pairs(self.keys) do size = size + 1 end
        if size >= self.cap then
            local evict = self.freqs[self.min_freq][1]
            table.remove(self.freqs[self.min_freq], 1)
            self.keys[evict] = nil
        end
        self.keys[key] = {val=val, freq=1}
        if not self.freqs[1] then self.freqs[1] = {} end
        table.insert(self.freqs[1], key)
        self.min_freq = 1
    end

    return c
end

function M.problem67()
    print("Problem 67:")
    local c = M.new_lfu_cache(2)
    c:set(1,1); c:set(2,2)
    assert(c:get(1) == 1)
    c:set(3,3)
    assert(c:get(2) == nil)
    assert(c:get(3) == 3)
    print("All Tests Passed")
end

return M
