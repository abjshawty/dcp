package main

import "fmt"

// LockNode is a binary tree node that supports locking with O(h) methods.
// Each node tracks its parent pointer and a count of locked descendants,
// which lets us check ancestors in O(h) and descendants in O(1).
type LockNode struct {
	val             int
	locked          bool
	lockedDescCount int
	parent          *LockNode
	left            *LockNode
	right           *LockNode
}

func newLockNode(val int, parent *LockNode) *LockNode {
	return &LockNode{val: val, parent: parent}
}

func (n *LockNode) isLocked() bool { return n.locked }

// canLockOrUnlock returns true if no ancestor is locked and lockedDescCount==0.
func (n *LockNode) canLockOrUnlock() bool {
	if n.lockedDescCount > 0 {
		return false
	}
	for p := n.parent; p != nil; p = p.parent {
		if p.locked {
			return false
		}
	}
	return true
}

func (n *LockNode) lock() bool {
	if n.locked || !n.canLockOrUnlock() {
		return false
	}
	n.locked = true
	for p := n.parent; p != nil; p = p.parent {
		p.lockedDescCount++
	}
	return true
}

func (n *LockNode) unlock() bool {
	if !n.locked || !n.canLockOrUnlock() {
		return false
	}
	n.locked = false
	for p := n.parent; p != nil; p = p.parent {
		p.lockedDescCount--
	}
	return true
}

func problem24() {
	fmt.Println("Problem 24:")
	root := newLockNode(1, nil)
	root.left = newLockNode(2, root)
	root.right = newLockNode(3, root)
	root.left.left = newLockNode(4, root.left)

	if !root.left.lock() { panic("assertion failed") }
	if root.left.isLocked() != true { panic("assertion failed") }
	if root.lock() { panic("assertion failed") }             // ancestor check: root has locked descendant
	if root.left.left.lock() { panic("assertion failed") }  // ancestor locked
	if !root.left.unlock() { panic("assertion failed") }
	if root.left.isLocked() != false { panic("assertion failed") }
	if !root.lock() { panic("assertion failed") }            // now free
	fmt.Println("All Tests Passed")
}
