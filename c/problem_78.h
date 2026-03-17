#ifndef PROBLEM_78_H
#define PROBLEM_78_H

typedef struct ListNode78 { int val; struct ListNode78 *next; } ListNode78;

ListNode78 *merge_k_lists(ListNode78 **lists, int k);
void problem78(void);

#endif
