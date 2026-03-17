#include "problem_44.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static long long merge_count(long long *arr, long long *tmp, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long cnt = merge_count(arr, tmp, l, mid) + merge_count(arr, tmp, mid+1, r);
    int i = l, j = mid+1, k = l;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else { tmp[k++] = arr[j++]; cnt += mid - i + 1; }
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= r)   tmp[k++] = arr[j++];
    memcpy(arr+l, tmp+l, (r-l+1)*sizeof(long long));
    return cnt;
}

long long count_inversions(long long *arr, int n) {
    long long *tmp = malloc(n * sizeof(long long));
    long long result = merge_count(arr, tmp, 0, n-1);
    free(tmp);
    return result;
}

void problem44(void) {
    printf("Problem 44:\n");
    long long a[] = {2,4,1,3,5};
    assert(count_inversions(a, 5) == 3);
    long long b[] = {5,4,3,2,1};
    assert(count_inversions(b, 5) == 10);
    long long c[] = {1,2,3};
    assert(count_inversions(c, 3) == 0);
    printf("All Tests Passed\n");
}
