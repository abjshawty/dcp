def find_pair_with_sum(numbers: list[int], k: int) -> bool:
    for i in numbers:
        if k - i in numbers:
            return True
    return False


def main():
    assert find_pair_with_sum([10, 15, 3, 7], 17), "Test failed: find_pair_with_sum() should return True for [10, 15, 3, 7] and 17"
    print("All tests passed")
if __name__ == "__main__":
    main()