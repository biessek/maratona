#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int fat[2502][500];

int prim[500], qtp;

void cfat() {
    memset(fat[0],0,sizeof(fat[0]));
    memset(fat[1],0,sizeof(fat[1]));
    fat[0][1]=fat[1][1]=1;
    int i, j, num;
    for(i=2;i<=2501;i++) {
        num=i;
        memset(fat[i],0,sizeof(fat[i]));
        for(j=0;j<15;j++) {
            while(num%prim[j]==0) {fat[i][prim[j]]++; num/=prim[j]; }
            fat[i][prim[j]]+=fat[i-1][prim[j]];
        }            
    }    
}

int a, b, c;
int cfa[52], cfb[52], cfc[52];

long long fe(long long n, long long p) {
    if(p==1) return n;
    long long r = 1;
    while(p>0) {
        if( p & 1) r= (r * n) % INT_MAX;
        p=p>>1;
        n= (n * n) % INT_MAX;
    }
    return r;
    
}

int main() {
    cfat();
    
    int n, i, A, B, C, k, num;
    long long j, desc;
    long long pA, pB, pC;
    scanf("%d", &n);
    
    for(i=1;i<=n;i++) {
        for(k=0;k<=15;k++) { cfa[prim[k]]=cfb[prim[k]]=cfc[prim[k]]=0;}
        
        scanf("%d %d %d", &A, &B, &C);
        
        for(j=0;j<A;j++) {
            scanf("%d", &a); 
            for(k=0;k<15;k++) { cfa[prim[k]]+=fat[a][prim[k]]; }           
        }
        for(j=0;j<B;j++) {
            scanf("%d", &b);
            for(k=0;k<15;k++) { cfb[prim[k]]+=fat[b][prim[k]]; }           
        }
        for(j=0;j<C;j++) {
            scanf("%d", &c);
            for(k=0;k<15;k++) { cfc[prim[k]]+=fat[c][prim[k]]; }           
        }
        pA=pB=pC=1;
        for(k=0;k<15;k++) { 
            desc=min(min(cfa[prim[k]],cfb[prim[k]]),cfc[prim[k]]);                
            cfa[prim[k]]-=desc; cfb[prim[k]]-=desc; cfc[prim[k]]-=desc;
            printf("%d=%d|%d|%d\n",prim[k],cfa[prim[k]],cfb[prim[k]],cfc[prim[k]]);
            pA=(pA*fe(prim[k],cfa[prim[k]]))%INT_MAX;
            pB=(pB*fe(prim[k],cfb[prim[k]]))%INT_MAX;
            pC=(pC*fe(prim[k],cfc[prim[k]]))%INT_MAX;
        }           
        
        printf("CASO #%d: ", i);
 //       printf("\n%lli\n", pA);    
 //       printf("%lli\n", pB);    
 //       printf("%lli\n", pC);    puts("");
        if(pA>pB&&pA>pC) puts("A");
        else if(pA<pB&&pB>pC) puts("B");
        else if(pA<pC&&pB<pC) puts("C");
        else puts("EMPATARAM");
    }
    return 0;
}
