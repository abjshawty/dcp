#include "problem_21.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int cmpInterval(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

/* minRooms: sort + sorted ends array. O(n log n). */
int minRooms(Interval *intervals, int n) {
    if (n == 0) return 0;
    qsort(intervals, n, sizeof(Interval), cmpInterval);
    int ends[256]; /* sorted end times */
    int endCount = 0;

    for (int i = 0; i < n; i++) {
        if (endCount > 0 && ends[0] <= intervals[i].start) {
            /* reuse earliest-ending room — remove ends[0] */
            for (int j = 1; j < endCount; j++) ends[j-1] = ends[j];
            endCount--;
        }
        /* insert intervals[i].end keeping ends sorted */
        int pos = endCount;
        for (int j = 0; j < endCount; j++) {
            if (ends[j] > intervals[i].end) { pos = j; break; }
        }
        for (int j = endCount; j > pos; j--) ends[j] = ends[j-1];
        ends[pos] = intervals[i].end;
        endCount++;
    }
    return endCount;
}

void problem21(void) {
    printf("Problem 21:\n");
    Interval a[] = {{30,75},{0,50},{60,150}};
    Interval b[] = {{0,10},{10,20}};
    Interval c[] = {{0,10},{0,10}};
    assert(minRooms(a, 3) == 2);
    assert(minRooms(b, 2) == 1);
    assert(minRooms(c, 2) == 2);
    printf("All Tests Passed\n");
}
