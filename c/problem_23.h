#ifndef PROBLEM_23_H
#define PROBLEM_23_H

/* shortestPath returns minimum steps, or -1 if unreachable.
 * grid is rows x cols boolean array (1 = wall). */
int  shortestPath(int rows, int cols, int grid[rows][cols],
                  int startR, int startC, int endR, int endC);
void problem23(void);

#endif
