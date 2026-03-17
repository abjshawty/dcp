#ifndef PROBLEM_22_H
#define PROBLEM_22_H

/* wordBreak fills result[] with the split words and returns the count,
 * or -1 if no reconstruction is possible. */
int  wordBreak(const char *s, const char **words, int numWords,
               char result[][64], int maxResults);
void problem22(void);

#endif
