#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

long long cf[2501];
long long PM =1000000007;
long long MOD =1000000007;

void c() {
    cf[0]=cf[1]=1;
    for(long long i=2;i<2501;i++) {
        cf[i]=(cf[i-1] * i) % PM;
    }
}
char m[51][53];
int ac[51][51];

long long expbin(long long a, long long b) {
  long long y;
  if (b == 0) return 1;
  if (b & 1) return a * expbin(a, b - 1) % MOD;
  y = expbin(a, b >> 1);
  return y * y % MOD;
}
 
long long binom(int n, int k) {
  return cf[n] * expbin(cf[k] * cf[n - k] % MOD, MOD - 2) % MOD;
}

int main() {
    int N, M, i, j, i1, j1, i2, j2, k, n, df;
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
        df=n-k;
        printf("%lli\n", binom(n,k)-1);
        
    }
    
    return 0;
}
