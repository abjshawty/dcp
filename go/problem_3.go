package main

import (
	"fmt"
	"strings"
)

// Node is a binary tree node with a string value and left/right children.
type Node struct {
	val   string
	left  *Node
	right *Node
}

// serialize encodes a binary tree into a comma-separated string using
// pre-order traversal. Null nodes are represented with the sentinel "#".
func serialize(root *Node) string {
	if root == nil {
		return "#"
	}
	// pre-order: root, left subtree, right subtree
	return root.val + "," + serialize(root.left) + "," + serialize(root.right)
}

// deserialize reconstructs a binary tree from a string produced by serialize.
// It consumes tokens from a shared iterator, mirroring the pre-order encoding.
func deserialize(s string) *Node {
	tokens := strings.Split(s, ",")
	idx := 0

	var build func() *Node
	build = func() *Node {
		val := tokens[idx]
		idx++
		if val == "#" { // sentinel marks a null node
			return nil
		}
		// reconstruct pre-order: node first, then left and right subtrees
		return &Node{val, build(), build()}
	}

	return build()
}

func problem3() {
	fmt.Println("Problem 3:")
	node := &Node{"root", &Node{"left", &Node{"left.left", nil, nil}, nil}, &Node{"right", nil, nil}}
	result := deserialize(serialize(node))
	if result.left.left.val != "left.left" {
		panic("assertion failed")
	}
	fmt.Println("All Tests Passed")
}
