from typing import Callable

# cons constructs a pair encoded as a closure. car and cdr extract the first
# and second elements by passing selector functions into the pair.
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

# car returns the first element of a pair.
def car(pair) -> int:
    return pair(lambda a, b: a)

# cdr returns the second element of a pair.
def cdr(pair) -> int:
    return pair(lambda a, b: b)


def main():
    print("Problem 5:")
    assert car(cons(3, 4)) == 3,  "assertion failed"
    assert cdr(cons(3, 4)) == 4,  "assertion failed"
    assert car(cons(0, -1)) == 0, "assertion failed"
    assert cdr(cons(0, -1)) == -1, "assertion failed"
    print("All Tests Passed")
