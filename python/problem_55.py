import secrets
from typing import Optional


class URLShortener:
    def __init__(self):
        self._s2l = {}
        self._l2s = {}

    def shorten(self, url: str) -> str:
        if url in self._l2s:
            return self._l2s[url]
        short = secrets.token_hex(3)
        self._s2l[short] = url
        self._l2s[url] = short
        return short

    def restore(self, short: str) -> Optional[str]:
        return self._s2l.get(short)


def main():
    print("Problem 55:")
    us = URLShortener()
    s1 = us.shorten("https://example.com")
    assert len(s1) > 0
    assert us.restore(s1) == "https://example.com"
    assert us.shorten("https://example.com") == s1
    assert us.restore("notexist") is None
    print("All Tests Passed")
