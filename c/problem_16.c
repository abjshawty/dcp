#include "problem_16.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void orderLogInit(OrderLog *l, int n) {
    memset(l->buf, 0, sizeof(l->buf));
    l->n = n; l->pos = 0;
}

void orderLogRecord(OrderLog *l, int orderId) {
    l->buf[l->pos] = orderId;
    l->pos = (l->pos + 1) % l->n;
}

/* orderLogGetLast: i=1 returns most recent. */
int orderLogGetLast(const OrderLog *l, int i) {
    return l->buf[(l->pos - i + l->n) % l->n];
}

void problem16(void) {
    printf("Problem 16:\n");
    OrderLog log;
    orderLogInit(&log, 3);
    orderLogRecord(&log, 1); orderLogRecord(&log, 2); orderLogRecord(&log, 3);
    assert(orderLogGetLast(&log, 1) == 3);
    assert(orderLogGetLast(&log, 2) == 2);
    assert(orderLogGetLast(&log, 3) == 1);
    orderLogRecord(&log, 4);
    assert(orderLogGetLast(&log, 1) == 4);
    assert(orderLogGetLast(&log, 2) == 3);
    printf("All Tests Passed\n");
}
