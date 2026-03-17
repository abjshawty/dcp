package main

type TreeNode48 struct {
	val         string
	left, right *TreeNode48
}

func buildTree(preorder, inorder []string) *TreeNode48 {
	if len(preorder) == 0 {
		return nil
	}
	root := &TreeNode48{val: preorder[0]}
	idx := 0
	for i, v := range inorder {
		if v == preorder[0] {
			idx = i
			break
		}
	}
	root.left = buildTree(preorder[1:1+idx], inorder[:idx])
	root.right = buildTree(preorder[1+idx:], inorder[idx+1:])
	return root
}

func inorderTraversal48(root *TreeNode48) []string {
	if root == nil {
		return nil
	}
	result := inorderTraversal48(root.left)
	result = append(result, root.val)
	result = append(result, inorderTraversal48(root.right)...)
	return result
}

func problem48() {
	println("Problem 48:")
	pre := []string{"a", "b", "d", "e", "c", "f", "g"}
	in := []string{"d", "b", "e", "a", "f", "c", "g"}
	root := buildTree(pre, in)
	got := inorderTraversal48(root)
	assertSliceEqual(got, in)
	println("All Tests Passed")
}
