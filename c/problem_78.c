#include "problem_78.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

ListNode78 *merge_k_lists(ListNode78 **lists, int k) {
    ListNode78 dummy={0,NULL}, *cur=&dummy;
    while(1){
        int min_val=2147483647, min_idx=-1;
        for(int i=0;i<k;i++) if(lists[i]&&lists[i]->val<min_val){min_val=lists[i]->val;min_idx=i;}
        if(min_idx<0) break;
        cur->next=lists[min_idx]; cur=cur->next; lists[min_idx]=lists[min_idx]->next;
    }
    return dummy.next;
}

static ListNode78 *from_arr78(int *a,int n){
    ListNode78 *d=calloc(1,sizeof(ListNode78)),*c=d;
    for(int i=0;i<n;i++){c->next=calloc(1,sizeof(ListNode78));c=c->next;c->val=a[i];}
    return d->next;
}

void problem78(void) {
    printf("Problem 78:\n");
    int a[]={1,4,7},b[]={2,5,8},c[]={3,6,9};
    ListNode78 *lists[3]={from_arr78(a,3),from_arr78(b,3),from_arr78(c,3)};
    ListNode78 *result=merge_k_lists(lists,3);
    int exp[]={1,2,3,4,5,6,7,8,9},i=0;
    while(result){assert(result->val==exp[i++]);result=result->next;}
    assert(i==9);
    printf("All Tests Passed\n");
}
