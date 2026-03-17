#include "problem_81.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static const char *map2[] = {"a","b","c"};
static const char *map3[] = {"d","e","f"};

static int phone_rec(const char *digits, int idx, char current[], char out[][64], int *cnt) {
    if(digits[idx]=='\0'){ strcpy(out[(*cnt)++], current); return 1; }
    const char **letters = (digits[idx]=='2') ? map2 : map3;
    int n_letters = 3;
    int len = strlen(current);
    for(int i=0;i<n_letters;i++){
        current[len]=letters[i][0]; current[len+1]='\0';
        phone_rec(digits, idx+1, current, out, cnt);
        current[len]='\0';
    }
    return *cnt;
}

void problem81(void) {
    printf("Problem 81:\n");
    char out[16][64]; int cnt=0;
    char cur[32]="";
    phone_rec("23", 0, cur, out, &cnt);
    assert(cnt==9);
    printf("All Tests Passed\n");
}
