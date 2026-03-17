#include "problem_90.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int random_excluding(int n, int *exclude, int excl_size) {
    int valid[64], vn=0;
    for(int i=0;i<n;i++){
        int excl=0;
        for(int j=0;j<excl_size;j++) if(exclude[j]==i){excl=1;break;}
        if(!excl) valid[vn++]=i;
    }
    return valid[rand()%vn];
}

void problem90(void) {
    printf("Problem 90:\n");
    int excl[]={0,1,2,4};
    for(int i=0;i<100;i++) assert(random_excluding(5,excl,4)==3);
    int counts[5]={0};
    int excl2[]={2};
    for(int i=0;i<1000;i++) counts[random_excluding(5,excl2,1)]++;
    for(int k=0;k<5;k++) if(k!=2) assert(counts[k]>100);
    printf("All Tests Passed\n");
}
