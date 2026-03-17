def is_match(s: str, p: str) -> bool:
    m, n = len(s), len(p)
    dp = [[False] * (n + 1) for _ in range(m + 1)]
    dp[m][n] = True

    for j in range(n - 1, -1, -1):
        if j + 1 < n and p[j + 1] == '*':
            dp[m][j] = dp[m][j + 2]

    for i in range(m - 1, -1, -1):
        for j in range(n - 1, -1, -1):
            first_match = p[j] in ('.', s[i])
            if j + 1 < n and p[j + 1] == '*':
                dp[i][j] = dp[i][j + 2] or (first_match and dp[i + 1][j])
            else:
                dp[i][j] = first_match and dp[i + 1][j + 1]

    return dp[0][0]


def main():
    print("Problem 25:")
    assert is_match("ray",     "ra.")   == True
    assert is_match("raymond", "ra.")   == False
    assert is_match("chat",    ".*at")  == True
    assert is_match("chats",   ".*at")  == False
    assert is_match("",        "a*")    == True
    assert is_match("aaa",     "a*")    == True
    assert is_match("ab",      ".*")    == True
    print("All Tests Passed")
