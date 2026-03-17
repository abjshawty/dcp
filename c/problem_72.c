#include "problem_72.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int largest_value_path(const char *labels, int n, int edges[][2], int m) {
    int adj[16][16]={0}, indegree[16]={0};
    for(int i=0;i<m;i++){
        if(edges[i][0]==edges[i][1]) return -1;
        adj[edges[i][0]][edges[i][1]]=1; indegree[edges[i][1]]++;
    }
    int dp[16][26]={0};
    int queue[16], qs=0, qe=0;
    for(int i=0;i<n;i++) if(indegree[i]==0) queue[qe++]=i;
    int visited=0, best=0;
    while(qs<qe){
        int node=queue[qs++]; visited++;
        int c=labels[node]-'A';
        dp[node][c]++;
        for(int k=0;k<26;k++) if(dp[node][k]>best) best=dp[node][k];
        for(int nb=0;nb<n;nb++) if(adj[node][nb]){
            for(int k=0;k<26;k++) if(dp[node][k]>dp[nb][k]) dp[nb][k]=dp[node][k];
            if(--indegree[nb]==0) queue[qe++]=nb;
        }
    }
    return (visited==n)?best:-1;
}

void problem72(void) {
    printf("Problem 72:\n");
    int e1[4][2]={{0,1},{0,2},{2,3},{3,4}};
    assert(largest_value_path("ABACA",5,e1,4)==3);
    int e2[1][2]={{0,0}};
    assert(largest_value_path("A",1,e2,1)==-1);
    printf("All Tests Passed\n");
}
