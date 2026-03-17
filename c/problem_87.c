#include "problem_87.h"
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <assert.h>

#define MAX_NODES 16
static double x_lo[MAX_NODES], x_hi[MAX_NODES], y_lo[MAX_NODES], y_hi[MAX_NODES];
static char node_names[MAX_NODES][4];
static int n_nodes;

static int get_node(const char *name) {
    for(int i=0;i<n_nodes;i++) if(strcmp(node_names[i],name)==0) return i;
    strncpy(node_names[n_nodes],name,3);
    x_lo[n_nodes]=-DBL_MAX; x_hi[n_nodes]=DBL_MAX;
    y_lo[n_nodes]=-DBL_MAX; y_hi[n_nodes]=DBL_MAX;
    return n_nodes++;
}

int validate_rules(const char **rules, int n) {
    n_nodes=0;
    for(int i=0;i<n;i++){
        char a[4], dir[4], b[4];
        if(sscanf(rules[i],"%3s %3s %3s",a,dir,b)!=3) continue;
        int ai=get_node(a), bi=get_node(b);
        double eps=1.0;
        if     (!strcmp(dir,"N"))  y_lo[ai] = y_lo[ai]<y_lo[bi]+eps ? y_lo[bi]+eps : y_lo[ai];
        else if(!strcmp(dir,"S"))  y_hi[ai] = y_hi[ai]>y_hi[bi]-eps ? y_hi[bi]-eps : y_hi[ai];
        else if(!strcmp(dir,"E"))  x_lo[ai] = x_lo[ai]<x_lo[bi]+eps ? x_lo[bi]+eps : x_lo[ai];
        else if(!strcmp(dir,"W"))  x_hi[ai] = x_hi[ai]>x_hi[bi]-eps ? x_hi[bi]-eps : x_hi[ai];
        else if(!strcmp(dir,"NE")){y_lo[ai]=y_lo[ai]<y_lo[bi]+eps?y_lo[bi]+eps:y_lo[ai]; x_lo[ai]=x_lo[ai]<x_lo[bi]+eps?x_lo[bi]+eps:x_lo[ai];}
        else if(!strcmp(dir,"NW")){y_lo[ai]=y_lo[ai]<y_lo[bi]+eps?y_lo[bi]+eps:y_lo[ai]; x_hi[ai]=x_hi[ai]>x_hi[bi]-eps?x_hi[bi]-eps:x_hi[ai];}
        else if(!strcmp(dir,"SE")){y_hi[ai]=y_hi[ai]>y_hi[bi]-eps?y_hi[bi]-eps:y_hi[ai]; x_lo[ai]=x_lo[ai]<x_lo[bi]+eps?x_lo[bi]+eps:x_lo[ai];}
        else if(!strcmp(dir,"SW")){y_hi[ai]=y_hi[ai]>y_hi[bi]-eps?y_hi[bi]-eps:y_hi[ai]; x_hi[ai]=x_hi[ai]>x_hi[bi]-eps?x_hi[bi]-eps:x_hi[ai];}
        for(int j=0;j<n_nodes;j++){
            if(x_lo[j]>=x_hi[j]||y_lo[j]>=y_hi[j]) return 0;
        }
    }
    return 1;
}

void problem87(void) {
    printf("Problem 87:\n");
    const char *r1[]={"A N B","B NE C","C N A"};
    assert(!validate_rules(r1,3));
    const char *r2[]={"A NW B","A N B"};
    assert( validate_rules(r2,2));
    printf("All Tests Passed\n");
}
