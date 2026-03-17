#include "problem_58.h"
#include <stdio.h>
#include <assert.h>

int search_rotated(long long *arr, int n, long long target) {
    int lo=0, hi=n-1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (arr[mid]==target) return mid;
        if (arr[lo]<=arr[mid]) {
            if (arr[lo]<=target && target<arr[mid]) hi=mid-1; else lo=mid+1;
        } else {
            if (arr[mid]<target && target<=arr[hi]) lo=mid+1; else hi=mid-1;
        }
    }
    return -1;
}

void problem58(void) {
    printf("Problem 58:\n");
    long long a[] = {13,18,25,2,8,10};
    assert(search_rotated(a,6,8)==4);
    assert(search_rotated(a,6,13)==0);
    assert(search_rotated(a,6,99)==-1);
    printf("All Tests Passed\n");
}
