-- Trie supports O(|prefix|) insert and O(|prefix| + k) autocomplete.

local function newTrieNode()
    return { children = {}, isEnd = false }
end

local Trie = {}
Trie.__index = Trie

local function newTrie()
    return setmetatable({ root = newTrieNode() }, Trie)
end

function Trie:insert(word)
    local node = self.root
    for i = 1, #word do
        local ch = word:sub(i, i)
        if not node.children[ch] then
            node.children[ch] = newTrieNode()
        end
        node = node.children[ch]
    end
    node.isEnd = true
end

local function collect(node, prefix, results)
    if node.isEnd then results[#results+1] = prefix end
    local keys = {}
    for k in pairs(node.children) do keys[#keys+1] = k end
    table.sort(keys)
    for _, ch in ipairs(keys) do
        collect(node.children[ch], prefix .. ch, results)
    end
end

-- autocomplete returns all words sharing the given prefix, sorted.
function Trie:autocomplete(prefix)
    local node = self.root
    for i = 1, #prefix do
        local ch = prefix:sub(i, i)
        if not node.children[ch] then return {} end
        node = node.children[ch]
    end
    local results = {}
    collect(node, prefix, results)
    return results
end

local function tablesEqual(a, b)
    if #a ~= #b then return false end
    for i = 1, #a do if a[i] ~= b[i] then return false end end
    return true
end

local function problem11()
    print("Problem 11:")
    local t = newTrie()
    for _, w in ipairs({"dog", "deer", "deal"}) do t:insert(w) end
    assert(tablesEqual(t:autocomplete("de"), {"deal", "deer"}), "assertion failed")
    assert(tablesEqual(t:autocomplete("xyz"), {}),              "assertion failed")
    print("All Tests Passed")
end

return { problem11 = problem11 }
