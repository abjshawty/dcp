package main

import "fmt"

// xorNode is a node in an XOR linked list. both holds the XOR of the
// previous and next node indices (using slice indices as stand-in for pointers).
type xorNode struct {
	val  int
	both int // prev_idx XOR next_idx; -1 used as null sentinel
}

// xorList is an XOR doubly-linked list backed by a slice of nodes.
// Using a slice lets us simulate pointer arithmetic in a GC language.
type xorList struct {
	nodes []xorNode
	head  int // index of first node (-1 if empty)
	tail  int // index of last node  (-1 if empty)
}

func newXorList() *xorList {
	return &xorList{head: -1, tail: -1}
}

// add appends an element to the end of the list.
func (l *xorList) add(val int) {
	idx := len(l.nodes)
	prev := l.tail
	// new node's both = prev XOR null(-1 XOR -1 = 0, but we use -1^-1 trick)
	// both = prev_idx XOR next_idx; next is -1 (none)
	both := prev ^ -1 // equivalent to prev XOR null
	_ = both          // stored below
	l.nodes = append(l.nodes, xorNode{val: val, both: prev ^ -1})
	if l.tail != -1 {
		// update old tail: its both was (prev_of_tail XOR -1), now XOR in new idx
		l.nodes[l.tail].both ^= (-1 ^ idx) // replace null with idx
	}
	l.tail = idx
	if l.head == -1 {
		l.head = idx
	}
}

// get returns the node value at the given 0-based index.
func (l *xorList) get(index int) int {
	prev := -1
	curr := l.head
	for i := 0; i < index; i++ {
		next := prev ^ l.nodes[curr].both // XOR out prev to get next
		prev = curr
		curr = next
	}
	return l.nodes[curr].val
}

func problem6() {
	fmt.Println("Problem 6:")
	lst := newXorList()
	lst.add(1)
	lst.add(2)
	lst.add(3)
	lst.add(4)
	if lst.get(0) != 1 { panic("assertion failed") }
	if lst.get(1) != 2 { panic("assertion failed") }
	if lst.get(2) != 3 { panic("assertion failed") }
	if lst.get(3) != 4 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
