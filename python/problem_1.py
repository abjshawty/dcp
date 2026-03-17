def find_pair_with_sum(numbers: list[int], k: int) -> bool:
    seen = set()
    for n in numbers:
        if (k - n) in seen:  # check if the complement was seen earlier
            return True
        seen.add(n)  # record this number for future iterations
    return False


def main():
    print("Problem 1:")
    assert find_pair_with_sum([10, 15, 3, 7], 17)  == True,  "assertion failed"
    assert find_pair_with_sum([10, 15, 3, 7], 100) == False, "assertion failed"
    print("All Tests Passed")