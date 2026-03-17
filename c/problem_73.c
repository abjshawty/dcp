#include "problem_73.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

ListNode73 *reverse_list(ListNode73 *head) {
    ListNode73 *prev=NULL, *curr=head;
    while(curr){ ListNode73 *nxt=curr->next; curr->next=prev; prev=curr; curr=nxt; }
    return prev;
}

static ListNode73 *from_arr(int *a, int n){
    ListNode73 *d=calloc(1,sizeof(ListNode73)),*c=d;
    for(int i=0;i<n;i++){c->next=calloc(1,sizeof(ListNode73));c=c->next;c->val=a[i];}
    return d->next;
}

void problem73(void) {
    printf("Problem 73:\n");
    int a[]={1,2,3,4,5};
    ListNode73 *head=from_arr(a,5), *rev=reverse_list(head);
    int exp[]={5,4,3,2,1}, i=0;
    while(rev){assert(rev->val==exp[i++]);rev=rev->next;}
    assert(reverse_list(NULL)==NULL);
    printf("All Tests Passed\n");
}
