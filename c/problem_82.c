#include "problem_82.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void reader82_init(Reader82 *r, const char *content) {
    r->content=content; r->pos=0; r->buf[0]='\0'; r->buf_len=0;
}

static void fill_buf(Reader82 *r) {
    int avail = strlen(r->content+r->pos);
    int take  = avail<7?avail:7;
    memcpy(r->buf+r->buf_len, r->content+r->pos, take);
    r->buf_len+=take; r->buf[r->buf_len]='\0'; r->pos+=take;
}

int reader82_read_n(Reader82 *r, int n, char *out) {
    while(r->buf_len<n) { fill_buf(r); if(r->pos>=(int)strlen(r->content)&&r->buf_len<n) break; }
    int take = r->buf_len<n?r->buf_len:n;
    memcpy(out, r->buf, take); out[take]='\0';
    memmove(r->buf, r->buf+take, r->buf_len-take+1); r->buf_len-=take;
    return take;
}

void problem82(void) {
    printf("Problem 82:\n");
    Reader82 r; reader82_init(&r,"Hello world");
    char out[32];
    reader82_read_n(&r,5,out); assert(strcmp(out,"Hello")==0);
    reader82_read_n(&r,1,out); assert(strcmp(out," ")==0);
    reader82_read_n(&r,5,out); assert(strcmp(out,"world")==0);
    reader82_read_n(&r,5,out); assert(strcmp(out,"")==0);
    printf("All Tests Passed\n");
}
