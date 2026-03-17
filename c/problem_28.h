#ifndef PROBLEM_28_H
#define PROBLEM_28_H

/* justifyText fills out[][128] with justified lines, returns line count. */
int  justifyText(const char **words, int numWords, int k,
                 char out[][128], int maxLines);
void problem28(void);

#endif
