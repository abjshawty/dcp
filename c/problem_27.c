#include "problem_27.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int isBalanced(const char *s) {
    char stack[1024];
    int top = 0;
    for (; *s; s++) {
        char c = *s;
        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == 0) return 0;
            char open = stack[--top];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) return 0;
        }
    }
    return top == 0;
}

void problem27(void) {
    printf("Problem 27:\n");
    assert( isBalanced("([])[]({})" ));
    assert(!isBalanced("([)]")       );
    assert(!isBalanced("(((()")      );
    assert( isBalanced("")           );
    assert( isBalanced("{[]}")       );
    printf("All Tests Passed\n");
}
