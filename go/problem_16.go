package main

import "fmt"

// orderLog records the last N order IDs using a circular buffer.
// record and getLast both run in O(1) time and O(N) space.
type orderLog struct {
	buf  []int
	n    int
	size int // number of entries recorded so far (capped at n)
	pos  int // next write position
}

func newOrderLog(n int) *orderLog {
	return &orderLog{buf: make([]int, n), n: n}
}

// record adds an order ID to the log.
func (l *orderLog) record(orderID int) {
	l.buf[l.pos] = orderID
	l.pos = (l.pos + 1) % l.n
	if l.size < l.n {
		l.size++
	}
}

// getLast returns the i-th last element (1 = most recent).
func (l *orderLog) getLast(i int) int {
	idx := (l.pos - i + l.n) % l.n
	return l.buf[idx]
}

func problem16() {
	fmt.Println("Problem 16:")
	log := newOrderLog(3)
	log.record(1)
	log.record(2)
	log.record(3)
	if log.getLast(1) != 3 { panic("assertion failed") }
	if log.getLast(2) != 2 { panic("assertion failed") }
	if log.getLast(3) != 1 { panic("assertion failed") }
	log.record(4) // overwrites 1
	if log.getLast(1) != 4 { panic("assertion failed") }
	if log.getLast(2) != 3 { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
