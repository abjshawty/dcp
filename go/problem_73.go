package main

type ListNode73 struct {
	val  int
	next *ListNode73
}

func reverseList(head *ListNode73) *ListNode73 {
	var prev *ListNode73
	curr := head
	for curr != nil {
		next := curr.next
		curr.next = prev
		prev = curr
		curr = next
	}
	return prev
}

func list73(vals ...int) *ListNode73 {
	dummy := &ListNode73{}
	cur := dummy
	for _, v := range vals {
		cur.next = &ListNode73{val: v}
		cur = cur.next
	}
	return dummy.next
}

func list73ToSlice(head *ListNode73) []int {
	var result []int
	for head != nil {
		result = append(result, head.val)
		head = head.next
	}
	return result
}

func problem73() {
	println("Problem 73:")
	assertIntSliceEqual(list73ToSlice(reverseList(list73(1, 2, 3, 4, 5))), []int{5, 4, 3, 2, 1})
	assertIntSliceEqual(list73ToSlice(reverseList(list73(1))), []int{1})
	if reverseList(nil) != nil {
		panic("nil should return nil")
	}
	println("All Tests Passed")
}
