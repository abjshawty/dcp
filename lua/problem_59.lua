local M = {}

local function simple_hash(s)
    local h = 0
    for i = 1, #s do
        h = (h * 31 + string.byte(s, i)) % (2^32)
    end
    return string.format("%x", h)
end

function M.new_file_syncer()
    local fs = {files = {}}
    function fs:put(name, content) self.files[name] = content end
    function fs:checksum(name) return simple_hash(self.files[name] or '') end
    function fs:sync_from(other)
        local transferred = {}
        for name, content in pairs(other.files) do
            if self:checksum(name) ~= other:checksum(name) then
                self.files[name] = content
                transferred[#transferred+1] = name
            end
        end
        return transferred
    end
    return fs
end

function M.problem59()
    print("Problem 59:")
    local a = M.new_file_syncer()
    local b = M.new_file_syncer()
    a:put("foo.txt", "hello world")
    a:put("bar.txt", "same content")
    b:put("bar.txt", "same content")
    local changed = b:sync_from(a)
    assert(#changed == 1 and changed[1] == "foo.txt")
    assert(b.files["foo.txt"] == "hello world")
    print("All Tests Passed")
end

return M
