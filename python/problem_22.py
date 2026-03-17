def word_break(s: str, words: list[str]) -> list[str] | None:
    # word_break reconstructs s from words using backtracking with memoisation.
    # Returns any valid split, or None if impossible.
    word_set = set(words)
    failed: set[int] = set()

    def backtrack(start: int) -> list[str] | None:
        if start == len(s):
            return []  # fully consumed
        if start in failed:
            return None
        for end in range(start + 1, len(s) + 1):
            word = s[start:end]
            if word in word_set:
                rest = backtrack(end)
                if rest is not None:
                    return [word] + rest
        failed.add(start)
        return None

    return backtrack(0)


def main():
    print("Problem 22:")
    r1 = word_break("thequickbrownfox", ["quick", "brown", "the", "fox"])
    assert r1 == ["the", "quick", "brown", "fox"], "assertion failed"
    r2 = word_break("bedbathandbeyond", ["bed", "bath", "bedbath", "and", "beyond"])
    assert r2 is not None, "assertion failed"
    assert word_break("xyz", ["a", "b"]) is None, "assertion failed"
    print("All Tests Passed")
