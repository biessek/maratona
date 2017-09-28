#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define PM 1000000007 
#define MAXN 1001

LL f[MAXN];

void ccb() {
    int i,j;
    f[0]=f[1]=1;
    for(i=2;i<MAXN;i++) {    
        f[i] = (i * f[i-1]) % PM;
    }
}

int main() {
    int k, i, tot;
    LL res;
    int q[MAXN];
    ccb(); 
    scanf("%d", &k);
    
    res=1;
    for(i=tot=0;i<k;i++) {
        scanf("%d", &q[i]);
        res = res * (f[tot]/((f[tot+q[i]-1]*f[q[i]-1])% PM)) % PM;
        tot+=q[i];
    }
    printf("%d\n",res);
    return 0;
}
