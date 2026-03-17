-- longestSubstringKDistinct returns the length of the longest substring
-- containing at most k distinct characters.
-- Uses a sliding window with a character-frequency table.
-- This runs in O(n) time and O(k) space.
local function longestSubstringKDistinct(s, k)
    local freq = {}
    local distinct = 0
    local left = 1
    local best = 0

    for right = 1, #s do
        local ch = s:sub(right, right)
        if not freq[ch] or freq[ch] == 0 then
            distinct = distinct + 1
            freq[ch] = 0
        end
        freq[ch] = freq[ch] + 1

        while distinct > k do
            local lch = s:sub(left, left)
            freq[lch] = freq[lch] - 1
            if freq[lch] == 0 then distinct = distinct - 1 end
            left = left + 1
        end

        if right - left + 1 > best then best = right - left + 1 end
    end
    return best
end

local function problem13()
    print("Problem 13:")
    assert(longestSubstringKDistinct("abcba", 2) == 3, "assertion failed")
    assert(longestSubstringKDistinct("aa", 1)    == 2, "assertion failed")
    assert(longestSubstringKDistinct("abc", 3)   == 3, "assertion failed")
    assert(longestSubstringKDistinct("", 2)      == 0, "assertion failed")
    print("All Tests Passed")
end

return { problem13 = problem13 }
