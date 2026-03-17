use std::collections::HashMap;

// TrieNode holds children and a flag marking end-of-word.
#[derive(Default)]
pub struct TrieNode {
    children: HashMap<char, TrieNode>,
    is_end: bool,
}

// Trie supports O(|prefix|) insert and O(|prefix| + k) autocomplete.
#[derive(Default)]
pub struct Trie {
    root: TrieNode,
}

impl Trie {
    pub fn new() -> Self { Self::default() }

    pub fn insert(&mut self, word: &str) {
        let mut node = &mut self.root;
        for ch in word.chars() {
            node = node.children.entry(ch).or_default();
        }
        node.is_end = true;
    }

    fn collect(node: &TrieNode, prefix: String, results: &mut Vec<String>) {
        if node.is_end { results.push(prefix.clone()); }
        let mut keys: Vec<char> = node.children.keys().cloned().collect();
        keys.sort();
        for ch in keys {
            Self::collect(&node.children[&ch], format!("{}{}", prefix, ch), results);
        }
    }

    // autocomplete returns all words sharing the given prefix, sorted.
    pub fn autocomplete(&self, prefix: &str) -> Vec<String> {
        let mut node = &self.root;
        for ch in prefix.chars() {
            match node.children.get(&ch) {
                Some(n) => node = n,
                None    => return vec![],
            }
        }
        let mut results = Vec::new();
        Self::collect(node, prefix.to_string(), &mut results);
        results
    }
}

pub fn problem11() {
    println!("Problem 11:");
    let mut t = Trie::new();
    for w in ["dog", "deer", "deal"] { t.insert(w); }
    let got = t.autocomplete("de");
    assert_eq!(got, vec!["deal", "deer"], "assertion failed");
    assert!(t.autocomplete("xyz").is_empty(), "assertion failed");
    println!("All Tests Passed");
}
