#include "problem_55.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void url_init(URLShortener55 *us) { us->size = 0; }

const char *url_shorten(URLShortener55 *us, const char *url) {
    for (int i=0; i<us->size; i++)
        if (strcmp(us->orig[i], url)==0) return us->shortened[i];
    int idx = us->size++;
    strncpy(us->orig[idx], url, 255);
    snprintf(us->shortened[idx], SHORT_LEN, "%06x", (unsigned)(rand() & 0xFFFFFF));
    return us->shortened[idx];
}

const char *url_restore(URLShortener55 *us, const char *s) {
    for (int i=0; i<us->size; i++)
        if (strcmp(us->shortened[i], s)==0) return us->orig[i];
    return NULL;
}

void problem55(void) {
    printf("Problem 55:\n");
    URLShortener55 us; url_init(&us);
    const char *s1 = url_shorten(&us, "https://example.com");
    assert(s1 && strlen(s1) > 0);
    assert(strcmp(url_restore(&us, s1), "https://example.com")==0);
    assert(strcmp(url_shorten(&us, "https://example.com"), s1)==0);
    assert(url_restore(&us, "notexist")==NULL);
    printf("All Tests Passed\n");
}
