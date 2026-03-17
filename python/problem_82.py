class Reader82:
    def __init__(self, content: str):
        self._content = content
        self._pos = 0
        self._buf = ''

    def _read7(self) -> str:
        chunk = self._content[self._pos:self._pos + 7]
        self._pos += len(chunk)
        return chunk

    def read_n(self, n: int) -> str:
        while len(self._buf) < n:
            chunk = self._read7()
            if not chunk:
                break
            self._buf += chunk
        result = self._buf[:n]
        self._buf = self._buf[n:]
        return result


def main():
    print("Problem 82:")
    r = Reader82("Hello world")
    assert r.read_n(5) == "Hello"
    assert r.read_n(1) == " "
    assert r.read_n(5) == "world"
    assert r.read_n(5) == ""
    print("All Tests Passed")
