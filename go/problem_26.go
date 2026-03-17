package main

import "fmt"

// removeKthLast removes the kth-last node from a singly linked list in one pass.
// Uses two pointers k apart; when the fast pointer reaches nil, slow is at the
// node just before the target.
type SLNode struct {
	val  int
	next *SLNode
}

func slList(vals ...int) *SLNode {
	dummy := &SLNode{}
	cur := dummy
	for _, v := range vals {
		cur.next = &SLNode{val: v}
		cur = cur.next
	}
	return dummy.next
}

func slToSlice(head *SLNode) []int {
	var out []int
	for head != nil {
		out = append(out, head.val)
		head = head.next
	}
	return out
}

func removeKthLast(head *SLNode, k int) *SLNode {
	dummy := &SLNode{next: head}
	fast, slow := dummy, dummy
	for i := 0; i <= k; i++ {
		fast = fast.next
	}
	for fast != nil {
		fast = fast.next
		slow = slow.next
	}
	slow.next = slow.next.next
	return dummy.next
}

func problem26() {
	fmt.Println("Problem 26:")
	got := slToSlice(removeKthLast(slList(1, 2, 3, 4, 5), 2))
	exp := []int{1, 2, 3, 5}
	if len(got) != len(exp) { panic("assertion failed") }
	for i := range exp {
		if got[i] != exp[i] { panic("assertion failed") }
	}
	got2 := slToSlice(removeKthLast(slList(1, 2, 3), 1))
	exp2 := []int{1, 2}
	if len(got2) != len(exp2) { panic("assertion failed") }
	for i := range exp2 {
		if got2[i] != exp2[i] { panic("assertion failed") }
	}
	fmt.Println("All Tests Passed")
}
