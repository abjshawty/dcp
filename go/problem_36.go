package main

import "fmt"

// BSTNode is a binary search tree node.
type BSTNode struct {
	val   int
	left  *BSTNode
	right *BSTNode
}

// secondLargest finds the second-largest value in a BST.
// The largest is the rightmost node. The second largest is either:
//   (a) the largest node in the left subtree of the rightmost node, or
//   (b) the parent of the rightmost node (if it has no left child).
func secondLargest(root *BSTNode) int {
	var parent, curr *BSTNode
	curr = root
	for curr.right != nil {
		parent = curr
		curr = curr.right
	}
	// curr is the largest node
	if curr.left != nil {
		// second largest = rightmost of curr.left
		node := curr.left
		for node.right != nil { node = node.right }
		return node.val
	}
	return parent.val
}

func problem36() {
	fmt.Println("Problem 36:")
	//       5
	//      / \
	//     3   7
	//    / \ / \
	//   2  4 6  8
	root := &BSTNode{5,
		&BSTNode{3, &BSTNode{2, nil, nil}, &BSTNode{4, nil, nil}},
		&BSTNode{7, &BSTNode{6, nil, nil}, &BSTNode{8, nil, nil}},
	}
	if secondLargest(root) != 7 { panic("assertion failed") }
	// Tree: 3 -> 4 -> 5
	root2 := &BSTNode{3, nil, &BSTNode{4, nil, &BSTNode{5, nil, nil}}}
	if secondLargest(root2) != 4 { panic("assertion failed") }
	// Tree: 5 with left subtree max = 4
	root3 := &BSTNode{5, &BSTNode{3, nil, &BSTNode{4, nil, nil}}, nil}
	if secondLargest(root3) != 4 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
