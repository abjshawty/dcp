def num_decodings(s: str) -> int:
    # num_decodings counts the number of ways to decode a numeric string.
    # Uses bottom-up DP: dp[i] = number of ways to decode s[i:].
    # This runs in O(n) time and O(n) space.
    n = len(s)
    dp = [0] * (n + 1)
    dp[n] = 1  # empty suffix: one way

    for i in range(n - 1, -1, -1):
        if s[i] == '0':
            dp[i] = 0  # leading zero — invalid
            continue
        dp[i] = dp[i + 1]  # single-digit decode

        # two-digit decode: valid if s[i:i+2] is between 10 and 26
        if i + 1 < n:
            two_digit = int(s[i:i+2])
            if 10 <= two_digit <= 26:
                dp[i] += dp[i + 2]

    return dp[0]


def main():
    print("Problem 7:")
    assert num_decodings("111") == 3, "assertion failed"
    assert num_decodings("12")  == 2, "assertion failed"
    assert num_decodings("226") == 3, "assertion failed"
    assert num_decodings("10")  == 1, "assertion failed"
    print("All Tests Passed")
