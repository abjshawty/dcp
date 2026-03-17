#ifndef PROBLEM_16_H
#define PROBLEM_16_H

#define ORDER_LOG_MAX 64

typedef struct {
    int buf[ORDER_LOG_MAX];
    int n;
    int pos;
} OrderLog;

void orderLogInit(OrderLog *l, int n);
void orderLogRecord(OrderLog *l, int orderId);
int  orderLogGetLast(const OrderLog *l, int i);
void problem16(void);

#endif
