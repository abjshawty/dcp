def longest_substring_k_distinct(s: str, k: int) -> int:
    # Uses a sliding window with a character-frequency dict.
    # Expand right; shrink left whenever distinct chars exceed k.
    # This runs in O(n) time and O(k) space.
    freq: dict[str, int] = {}
    left = best = 0

    for right, ch in enumerate(s):
        freq[ch] = freq.get(ch, 0) + 1  # expand window

        # shrink from left until at most k distinct chars remain
        while len(freq) > k:
            lch = s[left]
            freq[lch] -= 1
            if freq[lch] == 0:
                del freq[lch]
            left += 1

        best = max(best, right - left + 1)

    return best


def main():
    print("Problem 13:")
    assert longest_substring_k_distinct("abcba", 2) == 3, "assertion failed"
    assert longest_substring_k_distinct("aa", 1)    == 2, "assertion failed"
    assert longest_substring_k_distinct("abc", 3)   == 3, "assertion failed"
    assert longest_substring_k_distinct("", 2)      == 0, "assertion failed"
    print("All Tests Passed")
