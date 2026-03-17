#include "problem_35.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void sortRGB(char *arr, int n) {
    int lo = 0, mid = 0, hi = n - 1;
    while (mid <= hi) {
        if (arr[mid] == 'R') {
            char t = arr[lo]; arr[lo] = arr[mid]; arr[mid] = t;
            lo++; mid++;
        } else if (arr[mid] == 'G') {
            mid++;
        } else {
            char t = arr[mid]; arr[mid] = arr[hi]; arr[hi] = t;
            hi--;
        }
    }
}

void problem35(void) {
    printf("Problem 35:\n");
    char arr[] = "GBRRBRG";
    sortRGB(arr, 7);
    assert(strcmp(arr, "RRRGGBB") == 0);
    char arr2[] = "BGR";
    sortRGB(arr2, 3);
    assert(strcmp(arr2, "RGB") == 0);
    printf("All Tests Passed\n");
}
