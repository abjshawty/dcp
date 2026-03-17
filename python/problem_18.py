from collections import deque


def max_subarray_of_size_k(nums: list[int], k: int) -> list[int]:
    # max_subarray_of_size_k returns the max value of each sliding window.
    # Uses a monotonic deque of indices in decreasing value order.
    # This runs in O(n) time and O(k) space.
    dq: deque[int] = deque()  # stores indices; front is current window max
    result = []

    for i, val in enumerate(nums):
        # remove indices outside the window
        while dq and dq[0] < i - k + 1:
            dq.popleft()
        # remove smaller elements from the back
        while dq and nums[dq[-1]] < val:
            dq.pop()
        dq.append(i)

        if i >= k - 1:  # window is full
            result.append(nums[dq[0]])

    return result


def main():
    print("Problem 18:")
    assert max_subarray_of_size_k([10, 5, 2, 7, 8, 7], 3) == [10, 7, 8, 8], "assertion failed"
    assert max_subarray_of_size_k([1, 2, 3], 1)            == [1, 2, 3],     "assertion failed"
    print("All Tests Passed")
