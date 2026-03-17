#ifndef PROBLEM_82_H
#define PROBLEM_82_H

typedef struct { const char *content; int pos; char buf[64]; int buf_len; } Reader82;

void reader82_init(Reader82 *r, const char *content);
int  reader82_read_n(Reader82 *r, int n, char *out);
void problem82(void);

#endif
