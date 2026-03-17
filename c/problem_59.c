#include "problem_59.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define FS_CAP 16
typedef struct { char names[FS_CAP][64]; char contents[FS_CAP][256]; int size; } FileSyncer59;

static void fs_put(FileSyncer59 *f, const char *name, const char *content) {
    for (int i=0;i<f->size;i++) if(strcmp(f->names[i],name)==0){ strncpy(f->contents[i],content,255); return; }
    strncpy(f->names[f->size], name, 63);
    strncpy(f->contents[f->size], content, 255);
    f->size++;
}

static unsigned long fs_hash(const char *s) {
    unsigned long h = 5381;
    while (*s) h = h*31 + (unsigned char)*s++;
    return h;
}

static unsigned long fs_checksum(FileSyncer59 *f, const char *name) {
    for (int i=0;i<f->size;i++) if(strcmp(f->names[i],name)==0) return fs_hash(f->contents[i]);
    return 0;
}

static int fs_sync(FileSyncer59 *dst, FileSyncer59 *src, char changed[][64]) {
    int n = 0;
    for (int i=0;i<src->size;i++) {
        if (fs_checksum(dst, src->names[i]) != fs_checksum(src, src->names[i])) {
            fs_put(dst, src->names[i], src->contents[i]);
            if (changed) strcpy(changed[n], src->names[i]);
            n++;
        }
    }
    return n;
}

void problem59(void) {
    printf("Problem 59:\n");
    FileSyncer59 a={0}, b={0};
    fs_put(&a,"foo.txt","hello world"); fs_put(&a,"bar.txt","same content");
    fs_put(&b,"bar.txt","same content");
    char changed[8][64];
    int n = fs_sync(&b, &a, changed);
    assert(n==1 && strcmp(changed[0],"foo.txt")==0);
    int found=0;
    for(int i=0;i<b.size;i++) if(strcmp(b.names[i],"foo.txt")==0 && strcmp(b.contents[i],"hello world")==0) found=1;
    assert(found);
    printf("All Tests Passed\n");
}
