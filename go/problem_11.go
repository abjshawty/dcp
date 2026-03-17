package main

import (
	"fmt"
	"sort"
)

// autocomplete returns all strings in words that have prefix s.
// Uses a trie for O(|s| + k) lookup where k is the number of results.
type trieNode struct {
	children map[rune]*trieNode
	isEnd    bool
}

func newTrieNode() *trieNode {
	return &trieNode{children: make(map[rune]*trieNode)}
}

type trie struct {
	root *trieNode
}

func newTrie() *trie { return &trie{root: newTrieNode()} }

// insert adds a word into the trie.
func (t *trie) insert(word string) {
	node := t.root
	for _, ch := range word {
		if node.children[ch] == nil {
			node.children[ch] = newTrieNode()
		}
		node = node.children[ch]
	}
	node.isEnd = true
}

// collect gathers all words reachable from node, prepending prefix.
func collect(node *trieNode, prefix string, results *[]string) {
	if node.isEnd {
		*results = append(*results, prefix)
	}
	for ch, child := range node.children {
		collect(child, prefix+string(ch), results)
	}
}

// autocomplete returns all words sharing the given prefix, in sorted order.
func (t *trie) autocomplete(prefix string) []string {
	node := t.root
	for _, ch := range prefix {
		if node.children[ch] == nil {
			return nil // prefix not found
		}
		node = node.children[ch]
	}
	var results []string
	collect(node, prefix, &results)
	sort.Strings(results)
	return results
}

func problem11() {
	fmt.Println("Problem 11:")
	t := newTrie()
	for _, w := range []string{"dog", "deer", "deal"} {
		t.insert(w)
	}
	got := t.autocomplete("de")
	if len(got) != 2 || got[0] != "deal" || got[1] != "deer" {
		panic("assertion failed")
	}
	if len(t.autocomplete("xyz")) != 0 {
		panic("assertion failed")
	}
	fmt.Println("All Tests Passed")
}
