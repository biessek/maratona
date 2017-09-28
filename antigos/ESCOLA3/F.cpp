#include<cstdio>
#include<utility>
#include<algorithm>
#include <cstdlib>
#include<cstring>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int V[1000][1000];
int G[1000];
char ad[1000][1020];
bool vis[1000];
int casas[1000];

int main() {
    int N, comp, i, j;    
    scanf("%d", &N);
    for(i=0;i<N;i++) {
        G[i] = 0;
        vis[i]=false;
    }

    for(i=0;i<N;i++) {
        scanf(" %s", ad[i]);
        for(j=0;j<N;j++) {
            if(ad[i][j] == 'S') {
                V[i][G[i]++]=j;
            }
        }
    }
    comp=0;
    for(i=0;comp != -1 && i<N;i++) {
        if(vis[i]) continue;
        casas[comp] = G[i]; // conta essa pessoa
        vis[i]=true;
        for(j=0;j<G[i];j++) {
            vis[V[i][j]]=true;
            if(strcmp(ad[i],ad[V[i][j]]) != 0) {
                comp = -1;
                break;
            } // pessoa com a descrição igual
        }
        if(comp==-1) break;
        comp++; 
    }

    if(comp != -1) {
        printf("%d\n", comp);
        // ordena
        sort(casas,casas+comp, greater<int>());
        printf("%d", casas[0]);
        for(i=1;i<comp;i++) {
            printf(" %d", casas[i]);
        } puts("");
    } else {
        puts("-1");
    }
    
}
