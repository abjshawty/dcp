package main

import "container/heap"

type ListNode78 struct {
	val  int
	next *ListNode78
}

type minHeap78 []*ListNode78

func (h minHeap78) Len() int            { return len(h) }
func (h minHeap78) Less(i, j int) bool  { return h[i].val < h[j].val }
func (h minHeap78) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *minHeap78) Push(x interface{}) { *h = append(*h, x.(*ListNode78)) }
func (h *minHeap78) Pop() interface{} {
	old := *h; n := len(old); x := old[n-1]; *h = old[:n-1]; return x
}

func mergeKLists(lists []*ListNode78) *ListNode78 {
	h := &minHeap78{}
	for _, l := range lists {
		if l != nil {
			heap.Push(h, l)
		}
	}
	dummy := &ListNode78{}
	cur := dummy
	for h.Len() > 0 {
		node := heap.Pop(h).(*ListNode78)
		cur.next = node
		cur = cur.next
		if node.next != nil {
			heap.Push(h, node.next)
		}
	}
	return dummy.next
}

func list78(vals ...int) *ListNode78 {
	dummy := &ListNode78{}; cur := dummy
	for _, v := range vals { cur.next = &ListNode78{val: v}; cur = cur.next }
	return dummy.next
}

func list78ToSlice(head *ListNode78) []int {
	var r []int
	for head != nil { r = append(r, head.val); head = head.next }
	return r
}

func problem78() {
	println("Problem 78:")
	lists := []*ListNode78{list78(1, 4, 7), list78(2, 5, 8), list78(3, 6, 9)}
	got := list78ToSlice(mergeKLists(lists))
	assertIntSliceEqual(got, []int{1, 2, 3, 4, 5, 6, 7, 8, 9})
	println("All Tests Passed")
}
