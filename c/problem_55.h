#ifndef PROBLEM_55_H
#define PROBLEM_55_H

#define URL_CAP 64
#define SHORT_LEN 7

typedef struct { char orig[URL_CAP][256]; char shortened[URL_CAP][SHORT_LEN]; int size; } URLShortener55;

void url_init(URLShortener55 *us);
const char *url_shorten(URLShortener55 *us, const char *url);
const char *url_restore(URLShortener55 *us, const char *s);
void problem55(void);

#endif
