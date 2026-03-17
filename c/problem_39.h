#ifndef PROBLEM_39_H
#define PROBLEM_39_H

#define GOL_MAX_CELLS 1024

typedef struct { int r, c; } GOLCell;

typedef struct {
    GOLCell cells[GOL_MAX_CELLS];
    int count;
} GOLBoard;

void golStep(const GOLBoard *in, GOLBoard *out);
int  golContains(const GOLBoard *b, int r, int c);
void problem39(void);

#endif
