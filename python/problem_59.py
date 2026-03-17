import hashlib
from typing import List


class FileSyncer:
    def __init__(self):
        self._files = {}

    def put(self, name: str, content: str) -> None:
        self._files[name] = content

    def checksum(self, name: str) -> str:
        return hashlib.md5(self._files.get(name, '').encode()).hexdigest()

    def sync_from(self, other: 'FileSyncer') -> List[str]:
        transferred = []
        for name, content in other._files.items():
            if self.checksum(name) != other.checksum(name):
                self._files[name] = content
                transferred.append(name)
        return transferred


def main():
    print("Problem 59:")
    a, b = FileSyncer(), FileSyncer()
    a.put("foo.txt", "hello world")
    a.put("bar.txt", "same content")
    b.put("bar.txt", "same content")
    changed = b.sync_from(a)
    assert changed == ["foo.txt"]
    assert b._files["foo.txt"] == "hello world"
    print("All Tests Passed")
