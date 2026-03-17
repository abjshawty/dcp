local function justifyText(words, k)
    local lines = {}
    local i = 1
    while i <= #words do
        local lineLen = #words[i]
        local j = i + 1
        while j <= #words and lineLen + 1 + #words[j] <= k do
            lineLen = lineLen + 1 + #words[j]
            j = j + 1
        end
        local lineWords = {}
        for x = i, j - 1 do lineWords[#lineWords + 1] = words[x] end
        local gaps = j - i - 1

        if j > #words or gaps == 0 then
            local line = table.concat(lineWords, ' ')
            lines[#lines + 1] = line .. string.rep(' ', k - #line)
        else
            local totalChars = 0
            for _, w in ipairs(lineWords) do totalChars = totalChars + #w end
            local totalSpaces = k - totalChars
            local base = math.floor(totalSpaces / gaps)
            local extra = totalSpaces % gaps
            local line = ''
            for idx, w in ipairs(lineWords) do
                line = line .. w
                if idx <= gaps then
                    line = line .. string.rep(' ', base)
                    if idx - 1 < extra then line = line .. ' ' end
                end
            end
            lines[#lines + 1] = line
        end
        i = j
    end
    return lines
end

local function tableEq(a, b)
    if #a ~= #b then return false end
    for i = 1, #a do if a[i] ~= b[i] then return false end end
    return true
end

local function problem28()
    print("Problem 28:")
    local words = {"the","quick","brown","fox","jumps","over","the","lazy","dog"}
    local result = justifyText(words, 16)
    local expected = {"the  quick brown","fox  jumps  over","the   lazy   dog"}
    assert(tableEq(result, expected), "assertion failed")
    for _, line in ipairs(result) do assert(#line == 16, "wrong length") end
    print("All Tests Passed")
end

return { problem28 = problem28 }
