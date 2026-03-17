-- longestFilePath returns the character length of the longest absolute
-- path to a file in the encoded filesystem string.
-- Uses a depth-indexed table of cumulative path lengths.
-- This runs in O(n) time.
local function longestFilePath(input)
    local stack = { [0] = 0 }
    local best = 0

    for line in (input .. "\n"):gmatch("([^\n]*)\n") do
        local depth = 0
        while line:sub(depth + 1, depth + 1) == "\t" do depth = depth + 1 end
        local name = line:sub(depth + 1)
        local pathLen = stack[depth] + #name
        stack[depth + 1] = pathLen + 1  -- +1 for '/'

        if name:find("%.") then  -- it's a file
            if pathLen > best then best = pathLen end
        end
    end
    return best
end

local function problem17()
    print("Problem 17:")
    local fs = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
    assert(longestFilePath(fs) == 32, "assertion failed")
    assert(longestFilePath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") == 20, "assertion failed")
    assert(longestFilePath("a") == 0, "assertion failed")
    print("All Tests Passed")
end

return { problem17 = problem17 }
