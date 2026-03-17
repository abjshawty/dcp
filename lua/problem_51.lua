local M = {}

function M.shuffle(deck)
    for i = #deck, 2, -1 do
        local j = math.random(1, i)
        deck[i], deck[j] = deck[j], deck[i]
    end
end

function M.problem51()
    print("Problem 51:")
    local deck = {}
    for i = 1, 52 do deck[i] = i end
    M.shuffle(deck)
    local seen = {}
    for _, v in ipairs(deck) do
        assert(not seen[v], "duplicate card")
        seen[v] = true
    end
    assert(#deck == 52)
    print("All Tests Passed")
end

return M
