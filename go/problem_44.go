package main

func countInversions(arr []int) int {
	tmp := make([]int, len(arr))
	return mergeSort44(arr, tmp, 0, len(arr)-1)
}

func mergeSort44(arr, tmp []int, l, r int) int {
	if l >= r {
		return 0
	}
	mid := (l + r) / 2
	count := mergeSort44(arr, tmp, l, mid) + mergeSort44(arr, tmp, mid+1, r)
	i, j, k := l, mid+1, l
	for i <= mid && j <= r {
		if arr[i] <= arr[j] {
			tmp[k] = arr[i]
			i++
		} else {
			tmp[k] = arr[j]
			count += mid - i + 1
			j++
		}
		k++
	}
	for i <= mid {
		tmp[k] = arr[i]; i++; k++
	}
	for j <= r {
		tmp[k] = arr[j]; j++; k++
	}
	copy(arr[l:r+1], tmp[l:r+1])
	return count
}

func problem44() {
	println("Problem 44:")
	assertEqual(countInversions([]int{2, 4, 1, 3, 5}), 3)
	assertEqual(countInversions([]int{5, 4, 3, 2, 1}), 10)
	assertEqual(countInversions([]int{1, 2, 3}), 0)
	println("All Tests Passed")
}
