-- numDecodings counts the number of ways to decode a numeric string where
-- '1'–'9' map to a–z and '10'–'26' map to j–z.
-- Uses bottom-up DP: dp[i] = number of ways to decode s[i:].
-- This runs in O(n) time and O(n) space.
local function numDecodings(s)
    local n = #s
    local dp = {}
    for i = 0, n do dp[i] = 0 end
    dp[n] = 1  -- empty suffix: one way

    for i = n - 1, 0, -1 do
        local ch = s:sub(i+1, i+1)  -- Lua strings are 1-indexed
        if ch == '0' then
            dp[i] = 0
        else
            dp[i] = dp[i + 1]  -- single-digit decode
            if i + 1 < n then
                local two = tonumber(s:sub(i+1, i+2))
                if two >= 10 and two <= 26 then
                    dp[i] = dp[i] + dp[i + 2]
                end
            end
        end
    end
    return dp[0]
end

local function problem7()
    print("Problem 7:")
    assert(numDecodings("111") == 3, "assertion failed")
    assert(numDecodings("12")  == 2, "assertion failed")
    assert(numDecodings("226") == 3, "assertion failed")
    assert(numDecodings("10")  == 1, "assertion failed")
    print("All Tests Passed")
end

return { problem7 = problem7 }
