package main

type StackQueue struct {
	inbox, outbox []int
}

func (q *StackQueue) enqueue(val int) {
	q.inbox = append(q.inbox, val)
}

func (q *StackQueue) dequeue() (int, bool) {
	if len(q.outbox) == 0 {
		for len(q.inbox) > 0 {
			n := len(q.inbox)
			q.outbox = append(q.outbox, q.inbox[n-1])
			q.inbox = q.inbox[:n-1]
		}
	}
	if len(q.outbox) == 0 {
		return 0, false
	}
	n := len(q.outbox)
	v := q.outbox[n-1]
	q.outbox = q.outbox[:n-1]
	return v, true
}

func problem53() {
	println("Problem 53:")
	q := &StackQueue{}
	q.enqueue(1); q.enqueue(2); q.enqueue(3)
	v, _ := q.dequeue(); assertEqual(v, 1)
	v, _ = q.dequeue(); assertEqual(v, 2)
	q.enqueue(4)
	v, _ = q.dequeue(); assertEqual(v, 3)
	v, _ = q.dequeue(); assertEqual(v, 4)
	_, ok := q.dequeue()
	if ok {
		panic("should be empty")
	}
	println("All Tests Passed")
}
