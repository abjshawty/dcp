def is_balanced(s: str) -> bool:
    match = {')': '(', ']': '[', '}': '{'}
    stack = []
    for c in s:
        if c in '([{':
            stack.append(c)
        elif c in ')]}':
            if not stack or stack[-1] != match[c]:
                return False
            stack.pop()
    return len(stack) == 0


def main():
    print("Problem 27:")
    assert is_balanced("([])[]({})")  == True
    assert is_balanced("([)]")        == False
    assert is_balanced("(((()")       == False
    assert is_balanced("")            == True
    assert is_balanced("{[]}")        == True
    print("All Tests Passed")
