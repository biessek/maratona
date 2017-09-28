#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

long long cf[2501][2501];
long long PM =1000000007;
void c() {
    memset(cf[0],0,sizeof(cf[0]));
    for(int i=0;i<2501;i++) {
        cf[i][0]=cf[i][i]=1;
        for(int j=1;j<i;j++) {
            cf[i][j]= (cf[i-1][j] + cf[i-1][j-1] ) % PM;
        }
    }
}
char m[51][53];
int ac[51][51];

int main() {
    int N, M, i, j, i1, j1, i2, j2, k, n;
    c();
    scanf("%d %d\n", &N, &M);
    for(i=1;i<=N;i++) {
        scanf("%s\n", m[i]+1);
    }
    for(i=0;i<51;i++) {
        ac[i][0]=ac[0][i]=0;
    }
    for(i=1;i<=N;i++) {
        for(j=1;j<=M;j++) {                        
            ac[i][j] = ac[i][j-1] + ac[i-1][j] - ac[i-1][j-1] + int(m[i][j] == '#'); 
        }
    }
    while(scanf("%d %d %d %d", &i1, &j1, &i2, &j2 ) != EOF) {
        k = ac[i2][j2] - ac[i1-1][j2] - ac[i2][j1-1] + ac[i1-1][j1-1]; 
        n = (j2 - j1 + 1) * (i2 - i1 + 1);
//        printf("%d %d\n",n,k);
        printf("%lli\n", cf[n][k]-1);
        
    }
    
    return 0;
}
