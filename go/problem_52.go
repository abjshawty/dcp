package main

import "container/list"

type LRUCache struct {
	cap   int
	items map[int]*list.Element
	list  *list.List
}

type lruEntry struct{ key, val int }

func newLRUCache(cap int) *LRUCache {
	return &LRUCache{cap: cap, items: map[int]*list.Element{}, list: list.New()}
}

func (c *LRUCache) get(key int) (int, bool) {
	if el, ok := c.items[key]; ok {
		c.list.MoveToFront(el)
		return el.Value.(*lruEntry).val, true
	}
	return 0, false
}

func (c *LRUCache) set(key, val int) {
	if el, ok := c.items[key]; ok {
		el.Value.(*lruEntry).val = val
		c.list.MoveToFront(el)
		return
	}
	if c.list.Len() == c.cap {
		back := c.list.Back()
		c.list.Remove(back)
		delete(c.items, back.Value.(*lruEntry).key)
	}
	el := c.list.PushFront(&lruEntry{key, val})
	c.items[key] = el
}

func problem52() {
	println("Problem 52:")
	c := newLRUCache(2)
	c.set(1, 1)
	c.set(2, 2)
	v, ok := c.get(1)
	if !ok || v != 1 {
		panic("assertion failed")
	}
	c.set(3, 3)
	_, ok = c.get(2)
	if ok {
		panic("2 should have been evicted")
	}
	v, ok = c.get(3)
	if !ok || v != 3 {
		panic("assertion failed")
	}
	println("All Tests Passed")
}
