#include "problem_5.h"
#include <stdio.h>
#include <assert.h>

/* cons constructs a pair encoded as two ints passed by value.
 * car and cdr are implemented by simple struct accessors — the
 * "closure" approach from Python/JS becomes a plain struct in C. */
typedef struct { int a; int b; } Pair;

static Pair cons(int a, int b) { Pair p = {a, b}; return p; }
static int  car(Pair p)        { return p.a; }
static int  cdr(Pair p)        { return p.b; }

void problem5(void) {
    printf("Problem 5:\n");
    assert(car(cons(3,  4)) ==  3);
    assert(cdr(cons(3,  4)) ==  4);
    assert(car(cons(0, -1)) ==  0);
    assert(cdr(cons(0, -1)) == -1);
    printf("All Tests Passed\n");
}
