#ifndef PROBLEM_41_H
#define PROBLEM_41_H

/* findItinerary fills result[] with airport names and returns count, or -1 on failure. */
int  findItinerary41(const char flights[][2][8], int numFlights, const char *start,
                     char result[][8], int maxResult);
void problem41(void);

#endif
