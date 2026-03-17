def min_palindrome(s: str) -> str:
    n = len(s)
    dp = [[0] * n for _ in range(n)]
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j]:
                dp[i][j] = dp[i+1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1])

    def build(i: int, j: int) -> str:
        if i > j:   return ''
        if i == j:  return s[i]
        if s[i] == s[j]:
            return s[i] + build(i+1, j-1) + s[j]
        add_left  = s[j] + build(i, j-1) + s[j]
        add_right = s[i] + build(i+1, j) + s[i]
        if dp[i+1][j] < dp[i][j-1]:
            return add_right
        if dp[i][j-1] < dp[i+1][j]:
            return add_left
        return min(add_left, add_right)

    return build(0, n - 1)


def main():
    print("Problem 34:")
    assert min_palindrome("race")   == "ecarace"
    assert min_palindrome("google") == "elgoogle"
    assert min_palindrome("a")      == "a"
    assert min_palindrome("ab")     == "aba"
    print("All Tests Passed")
