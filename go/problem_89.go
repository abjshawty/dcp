package main

import "math"

type TreeNode89 struct {
	val         int
	left, right *TreeNode89
}

func isValidBST(root *TreeNode89, lo, hi int64) bool {
	if root == nil {
		return true
	}
	if int64(root.val) <= lo || int64(root.val) >= hi {
		return false
	}
	return isValidBST(root.left, lo, int64(root.val)) && isValidBST(root.right, int64(root.val), hi)
}

func problem89() {
	println("Problem 89:")
	valid := &TreeNode89{val: 5,
		left:  &TreeNode89{val: 3, left: &TreeNode89{val: 2}, right: &TreeNode89{val: 4}},
		right: &TreeNode89{val: 7, left: &TreeNode89{val: 6}, right: &TreeNode89{val: 8}},
	}
	invalid := &TreeNode89{val: 5,
		left:  &TreeNode89{val: 3},
		right: &TreeNode89{val: 4},
	}
	if !isValidBST(valid, math.MinInt64, math.MaxInt64) {
		panic("assertion failed")
	}
	if isValidBST(invalid, math.MinInt64, math.MaxInt64) {
		panic("assertion failed")
	}
	println("All Tests Passed")
}
