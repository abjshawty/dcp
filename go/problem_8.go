package main

import "fmt"

// intNode is a binary tree node with an integer value.
type intNode struct {
	val   int
	left  *intNode
	right *intNode
}

// countUnivalSubtrees counts subtrees where every node has the same value.
// A leaf is always unival. An internal node is unival if both children are
// unival and share the node's value. Uses a post-order DFS.
// Returns (isUnival, count).
func countUnivalHelper(root *intNode) (bool, int) {
	if root == nil {
		return true, 0 // null node is trivially unival
	}
	leftUnival, leftCount   := countUnivalHelper(root.left)
	rightUnival, rightCount := countUnivalHelper(root.right)
	count := leftCount + rightCount

	isUnival := leftUnival && rightUnival &&
		(root.left == nil  || root.left.val  == root.val) &&
		(root.right == nil || root.right.val == root.val)

	if isUnival {
		count++
	}
	return isUnival, count
}

func countUnivalSubtrees(root *intNode) int {
	_, count := countUnivalHelper(root)
	return count
}

func problem8() {
	fmt.Println("Problem 8:")
	//       0
	//      / \
	//     1   0
	//        / \
	//       1   0
	//      / \
	//     1   1
	root := &intNode{0,
		&intNode{1, nil, nil},
		&intNode{0,
			&intNode{1,
				&intNode{1, nil, nil},
				&intNode{1, nil, nil},
			},
			&intNode{0, nil, nil},
		},
	}
	if countUnivalSubtrees(root) != 5 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
