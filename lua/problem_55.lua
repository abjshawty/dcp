local M = {}

function M.new_url_shortener()
    local us = {s2l={}, l2s={}}
    function us:shorten(url)
        if self.l2s[url] then return self.l2s[url] end
        local short = string.format("%06x", math.random(0, 16777215))
        self.s2l[short] = url; self.l2s[url] = short
        return short
    end
    function us:restore(short) return self.s2l[short] end
    return us
end

function M.problem55()
    print("Problem 55:")
    local us = M.new_url_shortener()
    local s1 = us:shorten("https://example.com")
    assert(s1 ~= nil and #s1 > 0)
    assert(us:restore(s1) == "https://example.com")
    assert(us:shorten("https://example.com") == s1)
    assert(us:restore("notexist") == nil)
    print("All Tests Passed")
end

return M
