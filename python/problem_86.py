def min_parens_removal(s: str) -> int:
    open_count = close_count = 0
    for c in s:
        if c == '(':
            open_count += 1
        else:
            if open_count > 0:
                open_count -= 1
            else:
                close_count += 1
    return open_count + close_count


def main():
    print("Problem 86:")
    assert min_parens_removal("()())()") == 1
    assert min_parens_removal(")(")      == 2
    assert min_parens_removal("()()")    == 0
    print("All Tests Passed")
