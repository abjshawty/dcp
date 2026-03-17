from typing import List


def justify_text(words: List[str], k: int) -> List[str]:
    lines = []
    i = 0
    while i < len(words):
        line_len = len(words[i])
        j = i + 1
        while j < len(words) and line_len + 1 + len(words[j]) <= k:
            line_len += 1 + len(words[j])
            j += 1
        line_words = words[i:j]
        gaps = j - i - 1
        if j == len(words) or gaps == 0:
            line = ' '.join(line_words)
            lines.append(line + ' ' * (k - len(line)))
        else:
            total_chars = sum(len(w) for w in line_words)
            total_spaces = k - total_chars
            base, extra = divmod(total_spaces, gaps)
            line = ''
            for idx, w in enumerate(line_words):
                line += w
                if idx < gaps:
                    line += ' ' * base + (' ' if idx < extra else '')
            lines.append(line)
        i = j
    return lines


def main():
    print("Problem 28:")
    words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
    result = justify_text(words, 16)
    expected = ["the  quick brown", "fox  jumps  over", "the   lazy   dog"]
    assert result == expected, f"got {result}"
    assert all(len(line) == 16 for line in result)
    print("All Tests Passed")
