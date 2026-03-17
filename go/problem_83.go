package main

type TreeNode83 struct {
	val         int
	left, right *TreeNode83
}

func invertTree(root *TreeNode83) *TreeNode83 {
	if root == nil {
		return nil
	}
	root.left, root.right = invertTree(root.right), invertTree(root.left)
	return root
}

func inorder83(root *TreeNode83) []int {
	if root == nil {
		return nil
	}
	r := inorder83(root.left)
	r = append(r, root.val)
	r = append(r, inorder83(root.right)...)
	return r
}

func problem83() {
	println("Problem 83:")
	root := &TreeNode83{val: 4,
		left:  &TreeNode83{val: 2, left: &TreeNode83{val: 1}, right: &TreeNode83{val: 3}},
		right: &TreeNode83{val: 7, left: &TreeNode83{val: 6}, right: &TreeNode83{val: 9}},
	}
	inverted := invertTree(root)
	assertIntSliceEqual(inorder83(inverted), []int{9, 7, 6, 4, 3, 2, 1})
	println("All Tests Passed")
}
