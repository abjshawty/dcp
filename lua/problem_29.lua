local function rleEncode(s)
    if #s == 0 then return '' end
    local result = {}
    local count = 1
    for i = 2, #s do
        if s:sub(i, i) == s:sub(i - 1, i - 1) then
            count = count + 1
        else
            result[#result + 1] = tostring(count) .. s:sub(i - 1, i - 1)
            count = 1
        end
    end
    result[#result + 1] = tostring(count) .. s:sub(#s, #s)
    return table.concat(result)
end

local function rleDecode(s)
    local result = {}
    local i = 1
    while i <= #s do
        local j = i
        while j <= #s and s:sub(j, j):match('%d') do j = j + 1 end
        local count = tonumber(s:sub(i, j - 1))
        result[#result + 1] = string.rep(s:sub(j, j), count)
        i = j + 1
    end
    return table.concat(result)
end

local function problem29()
    print("Problem 29:")
    assert(rleEncode("AAAABBBCCDAA") == "4A3B2C1D2A",   "assertion failed")
    assert(rleDecode("4A3B2C1D2A")  == "AAAABBBCCDAA",  "assertion failed")
    assert(rleEncode("A")           == "1A",             "assertion failed")
    assert(rleDecode("1A")          == "A",              "assertion failed")
    assert(rleEncode("")            == "",               "assertion failed")
    print("All Tests Passed")
end

return { problem29 = problem29 }
