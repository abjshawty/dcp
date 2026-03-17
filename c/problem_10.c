#include "problem_10.h"
#include <stdio.h>
#include <assert.h>

#ifdef _WIN32
#include <windows.h>
/* schedule calls f after n milliseconds synchronously (busy-sleep). */
static void schedule(void (*f)(void), int n) { Sleep(n); f(); }
#else
#include <unistd.h>
static void schedule(void (*f)(void), int n) { usleep(n * 1000); f(); }
#endif

static int g_fired = 0;
static void callback(void) { g_fired = 1; }

void problem10(void) {
    printf("Problem 10:\n");
    g_fired = 0;
    schedule(callback, 5);  /* 5 ms */
    assert(g_fired == 1);
    printf("All Tests Passed\n");
}
