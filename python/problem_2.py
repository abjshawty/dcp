def product_of_array_except_self(numbers: list[int]) -> list[int]:
    product = 1
    for i in numbers:
        product *= i
    return [product // i for i in numbers]

def product_of_array_except_self_without_division(numbers: list[int]) -> list[int]:
    pass

def main():
    assert product_of_array_except_self([1, 2, 3, 4, 5]) == [120, 60, 40, 30, 24], "Test failed: product_of_array_except_self() should return [120, 60, 40, 30, 24] for [1, 2, 3, 4, 5]"
    assert product_of_array_except_self([3, 2, 1]) == [2, 3, 6], "Test failed: product_of_array_except_self() should return [2, 3, 6] for [3, 2, 1]"
    print("All tests passed")

if __name__ == "__main__":
    main()