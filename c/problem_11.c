#include "problem_11.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Trie implementation with fixed alphabet (lowercase a-z). */
#define ALPHA 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHA];
    int isEnd;
} TrieNode;

static TrieNode *newTrieNode(void) {
    TrieNode *n = calloc(1, sizeof(TrieNode));
    return n;
}

static void trieInsert(TrieNode *root, const char *word) {
    TrieNode *node = root;
    for (; *word; word++) {
        int idx = *word - 'a';
        if (!node->children[idx]) node->children[idx] = newTrieNode();
        node = node->children[idx];
    }
    node->isEnd = 1;
}

/* collect fills results[] with up to maxResults words reachable from node. */
static int collect(TrieNode *node, char *buf, int depth, char results[][32], int maxResults, int count) {
    if (node->isEnd && count < maxResults) {
        buf[depth] = '\0';
        strcpy(results[count++], buf);
    }
    for (int i = 0; i < ALPHA && count < maxResults; i++) {
        if (node->children[i]) {
            buf[depth] = (char)('a' + i);
            count = collect(node->children[i], buf, depth + 1, results, maxResults, count);
        }
    }
    return count;
}

/* autocomplete returns number of matching words, fills results[]. */
static int autocomplete(TrieNode *root, const char *prefix, char results[][32], int maxResults) {
    TrieNode *node = root;
    for (const char *p = prefix; *p; p++) {
        int idx = *p - 'a';
        if (!node->children[idx]) return 0;
        node = node->children[idx];
    }
    char buf[64];
    strcpy(buf, prefix);
    return collect(node, buf, (int)strlen(prefix), results, maxResults, 0);
}

static void freeTrie(TrieNode *node) {
    if (!node) return;
    for (int i = 0; i < ALPHA; i++) freeTrie(node->children[i]);
    free(node);
}

void problem11(void) {
    printf("Problem 11:\n");
    TrieNode *root = newTrieNode();
    trieInsert(root, "dog");
    trieInsert(root, "deer");
    trieInsert(root, "deal");
    char results[10][32];
    int count = autocomplete(root, "de", results, 10);
    assert(count == 2);
    assert(strcmp(results[0], "deal") == 0);
    assert(strcmp(results[1], "deer") == 0);
    assert(autocomplete(root, "xyz", results, 10) == 0);
    freeTrie(root);
    printf("All Tests Passed\n");
}
