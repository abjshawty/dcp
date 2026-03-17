#include "problem_41.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_AIRPORTS 64
#define MAX_FLIGHTS  128

static char   g_airports[MAX_AIRPORTS][8];
static int    g_airportCount;
static char   g_adj[MAX_AIRPORTS][MAX_FLIGHTS][8];
static int    g_adjLen[MAX_AIRPORTS];
static char   g_result41[MAX_FLIGHTS+1][8];
static int    g_resultLen;

static int airportIdx(const char *name) {
    for (int i = 0; i < g_airportCount; i++)
        if (strcmp(g_airports[i], name) == 0) return i;
    strncpy(g_airports[g_airportCount], name, 7);
    return g_airportCount++;
}

static int cmpStr(const void *a, const void *b) { return strcmp((char*)a, (char*)b); }

static void dfs41(int idx) {
    while (g_adjLen[idx] > 0) {
        char nxt[8]; strcpy(nxt, g_adj[idx][0]);
        memmove(g_adj[idx][0], g_adj[idx][1], (g_adjLen[idx]-1)*8);
        g_adjLen[idx]--;
        dfs41(airportIdx(nxt));
    }
    strcpy(g_result41[g_resultLen++], g_airports[idx]);
}

int findItinerary41(const char flights[][2][8], int numFlights, const char *start,
                    char result[][8], int maxResult) {
    g_airportCount = 0; g_resultLen = 0;
    memset(g_adjLen, 0, sizeof(g_adjLen));

    for (int i = 0; i < numFlights; i++) {
        int src = airportIdx(flights[i][0]);
        strncpy(g_adj[src][g_adjLen[src]++], flights[i][1], 7);
    }
    for (int i = 0; i < g_airportCount; i++)
        qsort(g_adj[i], g_adjLen[i], 8, cmpStr);

    dfs41(airportIdx(start));
    if (g_resultLen != numFlights + 1) return -1;
    /* result is reversed */
    for (int i = 0; i < g_resultLen; i++)
        strcpy(result[i], g_result41[g_resultLen - 1 - i]);
    return g_resultLen;
}

void problem41(void) {
    printf("Problem 41:\n");
    char f1[4][2][8] = {{"SFO","HKO"},{"YYZ","SFO"},{"YUL","YYZ"},{"HKO","ORD"}};
    char res[16][8];
    int  cnt = findItinerary41(f1, 4, "YUL", res, 16);
    assert(cnt == 5);
    const char *exp1[] = {"YUL","YYZ","SFO","HKO","ORD"};
    for (int i=0;i<5;i++) assert(strcmp(res[i],exp1[i])==0);

    char f2[2][2][8] = {{"SFO","COM"},{"COM","YYZ"}};
    assert(findItinerary41(f2, 2, "COM", res, 16) == -1);

    char f3[4][2][8] = {{"A","B"},{"A","C"},{"B","C"},{"C","A"}};
    cnt = findItinerary41(f3, 4, "A", res, 16);
    assert(cnt == 5);
    const char *exp3[] = {"A","B","C","A","C"};
    for (int i=0;i<5;i++) assert(strcmp(res[i],exp3[i])==0);
    printf("All Tests Passed\n");
}
