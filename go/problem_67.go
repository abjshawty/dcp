package main

import "container/list"

type LFUCache struct {
	cap     int
	minFreq int
	keys    map[int]*list.Element
	freqs   map[int]*list.List
}

type lfuEntry struct{ key, val, freq int }

func newLFUCache(cap int) *LFUCache {
	return &LFUCache{
		cap:   cap,
		keys:  map[int]*list.Element{},
		freqs: map[int]*list.List{},
	}
}

func (c *LFUCache) touch(el *list.Element) {
	e := el.Value.(*lfuEntry)
	c.freqs[e.freq].Remove(el)
	if c.freqs[e.freq].Len() == 0 {
		delete(c.freqs, e.freq)
		if c.minFreq == e.freq {
			c.minFreq++
		}
	}
	e.freq++
	if c.freqs[e.freq] == nil {
		c.freqs[e.freq] = list.New()
	}
	c.keys[e.key] = c.freqs[e.freq].PushFront(e)
}

func (c *LFUCache) get(key int) (int, bool) {
	el, ok := c.keys[key]
	if !ok {
		return 0, false
	}
	c.touch(el)
	return el.Value.(*lfuEntry).val, true
}

func (c *LFUCache) set(key, val int) {
	if c.cap == 0 {
		return
	}
	if el, ok := c.keys[key]; ok {
		el.Value.(*lfuEntry).val = val
		c.touch(el)
		return
	}
	if len(c.keys) == c.cap {
		lst := c.freqs[c.minFreq]
		evict := lst.Back()
		lst.Remove(evict)
		delete(c.keys, evict.Value.(*lfuEntry).key)
	}
	e := &lfuEntry{key, val, 1}
	if c.freqs[1] == nil {
		c.freqs[1] = list.New()
	}
	c.keys[key] = c.freqs[1].PushFront(e)
	c.minFreq = 1
}

func problem67() {
	println("Problem 67:")
	c := newLFUCache(2)
	c.set(1, 1); c.set(2, 2)
	v, ok := c.get(1)
	if !ok || v != 1 {
		panic("assertion failed")
	}
	c.set(3, 3)
	_, ok = c.get(2)
	if ok {
		panic("2 should be evicted (least frequent)")
	}
	v, ok = c.get(3)
	if !ok || v != 3 {
		panic("assertion failed")
	}
	println("All Tests Passed")
}
