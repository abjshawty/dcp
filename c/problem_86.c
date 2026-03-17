#include "problem_86.h"
#include <stdio.h>
#include <assert.h>

int min_parens_removal(const char *s) {
    int open=0, close=0;
    for(; *s; s++){
        if(*s=='(') open++;
        else { if(open>0) open--; else close++; }
    }
    return open+close;
}

void problem86(void) {
    printf("Problem 86:\n");
    assert(min_parens_removal("()())()")==1);
    assert(min_parens_removal(")(")==2);
    assert(min_parens_removal("()()")==0);
    printf("All Tests Passed\n");
}
