package main

import "fmt"

// listNode is a singly linked list node.
type listNode struct {
	val  int
	next *listNode
}

// intersectingNode finds the first node shared by two linked lists.
// Advances two pointers simultaneously; when one reaches the end it
// restarts at the head of the other list. They meet at the intersection
// after at most M+N steps. This runs in O(M+N) time and O(1) space.
func intersectingNode(headA, headB *listNode) *listNode {
	a, b := headA, headB
	for a != b {
		if a == nil {
			a = headB
		} else {
			a = a.next
		}
		if b == nil {
			b = headA
		} else {
			b = b.next
		}
	}
	return a
}

func problem20() {
	fmt.Println("Problem 20:")
	// shared tail: 8 -> 10
	shared := &listNode{8, &listNode{10, nil}}
	headA := &listNode{3, &listNode{7, shared}}
	headB := &listNode{99, &listNode{1, shared}}
	if intersectingNode(headA, headB) != shared { panic("assertion failed") }
	// no intersection
	a := &listNode{1, nil}
	b := &listNode{2, nil}
	if intersectingNode(a, b) != nil { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
