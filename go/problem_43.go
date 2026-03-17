package main

import "fmt"

// MaxStack supports push, pop, and max in O(1) by maintaining a parallel max-stack.
type MaxStack struct {
	data []int
	maxs []int
}

func (s *MaxStack) Push(val int) {
	s.data = append(s.data, val)
	if len(s.maxs) == 0 || val >= s.maxs[len(s.maxs)-1] {
		s.maxs = append(s.maxs, val)
	} else {
		s.maxs = append(s.maxs, s.maxs[len(s.maxs)-1])
	}
}

func (s *MaxStack) Pop() (int, bool) {
	if len(s.data) == 0 { return 0, false }
	top := s.data[len(s.data)-1]
	s.data = s.data[:len(s.data)-1]
	s.maxs = s.maxs[:len(s.maxs)-1]
	return top, true
}

func (s *MaxStack) Max() (int, bool) {
	if len(s.maxs) == 0 { return 0, false }
	return s.maxs[len(s.maxs)-1], true
}

func problem43() {
	fmt.Println("Problem 43:")
	s := &MaxStack{}
	s.Push(1); s.Push(3); s.Push(2)
	if m, _ := s.Max(); m != 3 { panic("assertion failed") }
	if v, _ := s.Pop(); v != 2 { panic("assertion failed") }
	if m, _ := s.Max(); m != 3 { panic("assertion failed") }
	if v, _ := s.Pop(); v != 3 { panic("assertion failed") }
	if m, _ := s.Max(); m != 1 { panic("assertion failed") }
	_, ok := (&MaxStack{}).Pop()
	if ok { panic("assertion failed") }
	fmt.Println("All Tests Passed")
}
