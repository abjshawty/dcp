from typing import List, Optional


def word_wrap(s: str, k: int) -> Optional[List[str]]:
    words = s.split()
    if not words:
        return None
    lines = []
    line = words[0]
    for w in words[1:]:
        if len(line) + 1 + len(w) <= k:
            line += ' ' + w
        else:
            lines.append(line)
            line = w
    lines.append(line)
    if any(len(l) > k for l in lines):
        return None
    return lines


def main():
    print("Problem 57:")
    got = word_wrap("the quick brown fox jumps over the lazy dog", 10)
    assert got == ["the quick", "brown fox", "jumps over", "the lazy", "dog"]
    assert word_wrap("toolongword", 5) is None
    print("All Tests Passed")
