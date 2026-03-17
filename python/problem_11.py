class TrieNode:
    def __init__(self):
        self.children: dict[str, 'TrieNode'] = {}
        self.is_end = False


class Trie:
    # Trie supports O(|prefix|) insert and O(|prefix| + k) autocomplete
    # where k is the number of matching words.
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for ch in word:
            node = node.children.setdefault(ch, TrieNode())
        node.is_end = True

    def _collect(self, node: TrieNode, prefix: str) -> list[str]:
        results = []
        if node.is_end:
            results.append(prefix)
        for ch, child in sorted(node.children.items()):
            results.extend(self._collect(child, prefix + ch))
        return results

    def autocomplete(self, prefix: str) -> list[str]:
        # returns all words sharing the given prefix, in sorted order
        node = self.root
        for ch in prefix:
            if ch not in node.children:
                return []  # prefix not found
            node = node.children[ch]
        return self._collect(node, prefix)


def main():
    print("Problem 11:")
    t = Trie()
    for w in ["dog", "deer", "deal"]:
        t.insert(w)
    assert t.autocomplete("de") == ["deal", "deer"], "assertion failed"
    assert t.autocomplete("xyz") == [],              "assertion failed"
    print("All Tests Passed")
