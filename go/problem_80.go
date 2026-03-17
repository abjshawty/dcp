package main

type TreeNode80 struct {
	val         string
	left, right *TreeNode80
}

func deepestNode(root *TreeNode80) (string, int) {
	if root == nil {
		return "", 0
	}
	lv, ld := deepestNode(root.left)
	rv, rd := deepestNode(root.right)
	if ld > rd {
		return lv, ld + 1
	}
	if rd > ld {
		return rv, rd + 1
	}
	return root.val, 1
}

func problem80() {
	println("Problem 80:")
	root := &TreeNode80{val: "a",
		left: &TreeNode80{val: "b",
			left: &TreeNode80{val: "d"},
		},
		right: &TreeNode80{val: "c"},
	}
	v, _ := deepestNode(root)
	assertEqual(v, "d")
	println("All Tests Passed")
}
