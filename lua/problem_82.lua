local M = {}

function M.new_reader(content)
    local r = {content=content, pos=1, buf=""}
    function r:read7()
        local s = self.content:sub(self.pos, self.pos+6)
        self.pos = self.pos + #s
        return s
    end
    function r:read_n(n)
        while #self.buf < n do
            local chunk = self:read7()
            if #chunk == 0 then break end
            self.buf = self.buf .. chunk
        end
        local result = self.buf:sub(1, n)
        self.buf = self.buf:sub(n+1)
        return result
    end
    return r
end

function M.problem82()
    print("Problem 82:")
    local r = M.new_reader("Hello world")
    assert(r:read_n(5) == "Hello")
    assert(r:read_n(1) == " ")
    assert(r:read_n(5) == "world")
    assert(r:read_n(5) == "")
    print("All Tests Passed")
end

return M
