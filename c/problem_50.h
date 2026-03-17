#ifndef PROBLEM_50_H
#define PROBLEM_50_H

typedef struct ExprNode50 {
    char op;
    double val;
    struct ExprNode50 *left, *right;
} ExprNode50;

double eval_expr(ExprNode50 *root);
void problem50(void);

#endif
