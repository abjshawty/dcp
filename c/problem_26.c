#include "problem_26.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

SL26Node *sl26List(const int *vals, int n) {
    SL26Node dummy = {0, NULL};
    SL26Node *cur = &dummy;
    for (int i = 0; i < n; i++) {
        cur->next = malloc(sizeof(SL26Node));
        cur->next->val = vals[i]; cur->next->next = NULL;
        cur = cur->next;
    }
    return dummy.next;
}

SL26Node *removeKthLast26(SL26Node *head, int k) {
    SL26Node dummy = {0, head};
    SL26Node *fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= k; i++) fast = fast->next;
    while (fast) { fast = fast->next; slow = slow->next; }
    SL26Node *del = slow->next;
    slow->next = del->next;
    free(del);
    return dummy.next;
}

static void sl26Free(SL26Node *head) {
    while (head) { SL26Node *n = head->next; free(head); head = n; }
}

void problem26(void) {
    printf("Problem 26:\n");
    int a[] = {1,2,3,4,5};
    SL26Node *h1 = removeKthLast26(sl26List(a, 5), 2);
    int exp1[] = {1,2,3,5};
    SL26Node *c1 = h1;
    for (int i = 0; i < 4; i++, c1 = c1->next) assert(c1->val == exp1[i]);
    sl26Free(h1);

    int b[] = {1,2,3};
    SL26Node *h2 = removeKthLast26(sl26List(b, 3), 1);
    assert(h2->val == 1 && h2->next->val == 2 && h2->next->next == NULL);
    sl26Free(h2);

    printf("All Tests Passed\n");
}
