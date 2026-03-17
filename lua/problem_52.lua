local M = {}

function M.new_lru_cache(cap)
    local cache = {cap = cap, order = {}, data = {}}

    function cache:get(key)
        if not self.data[key] then return nil end
        for i, k in ipairs(self.order) do
            if k == key then table.remove(self.order, i); break end
        end
        table.insert(self.order, key)
        return self.data[key]
    end

    function cache:set(key, val)
        if self.data[key] then
            for i, k in ipairs(self.order) do
                if k == key then table.remove(self.order, i); break end
            end
        elseif #self.order >= self.cap then
            local evict = table.remove(self.order, 1)
            self.data[evict] = nil
        end
        self.data[key] = val
        table.insert(self.order, key)
    end

    return cache
end

function M.problem52()
    print("Problem 52:")
    local c = M.new_lru_cache(2)
    c:set(1,1); c:set(2,2)
    assert(c:get(1) == 1)
    c:set(3,3)
    assert(c:get(2) == nil)
    assert(c:get(3) == 3)
    print("All Tests Passed")
end

return M
