def product_of_array_except_self(numbers: list[int]) -> list[int]:
    product = 1
    for i in numbers:
        product *= i
    return [product // i for i in numbers]

def product_of_array_except_self_without_division(numbers: list[int]) -> list[int]:
    n = len(numbers)
    result = [1] * n

    # first pass: result[i] = product of all elements to the left of i
    for i in range(1, n):
        result[i] = result[i - 1] * numbers[i - 1]

    # second pass: multiply in the product of all elements to the right of i
    suffix = 1
    for i in range(n - 1, -1, -1):
        result[i] *= suffix
        suffix *= numbers[i]

    return result

def main():
    print("Problem 2:")
    assert product_of_array_except_self([1, 2, 3, 4, 5])                  == [120, 60, 40, 30, 24], "assertion failed"
    assert product_of_array_except_self([3, 2, 1])                         == [2, 3, 6],             "assertion failed"
    assert product_of_array_except_self_without_division([1, 2, 3, 4, 5]) == [120, 60, 40, 30, 24], "assertion failed"
    assert product_of_array_except_self_without_division([3, 2, 1])        == [2, 3, 6],             "assertion failed"
    print("All Tests Passed")