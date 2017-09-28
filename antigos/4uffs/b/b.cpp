#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <algorithm>

struct tempo {
 int i,j;
} t[1000];

bool comp (const tempo &a,const tempo &b) {
    return a.i==b.i? a.j<b.j : a.i<b.i;
}

int main() {
    int N, i, j, maximo=0;
    int L[1000];
    scanf("%d", &N);

    for(i=0;i<N;i++) {
        scanf("%d %d", &t[i].i,&t[i].j);
    }
    std::sort(t,t+N,comp);
    L[0]=maximo=t[0].j-t[0].i;

    for(i=1;i<N;i++) {
        L[i]=t[i].j-t[i].i;
        for(j=i-1;j>=0;j--) {
            if(t[i].i >= t[j].j) {
                L[i] = std::max(L[i],L[j] + t[i].j-t[i].i);
            }
        }
        maximo=std::max(maximo,L[i]);
    }
    printf("%d\n", maximo);

    return 0;
}
