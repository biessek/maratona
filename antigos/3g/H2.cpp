#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
#include<queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> uii;
typedef vector<ii> vii;
const int INF = (int)1e9;
int X[110][60];
int main() {
    int N, K, i;
    int C[5];
    int F[110];
    scanf("%d %d", &N, &K);
    for(i=1;i<=N;i++) {
        scanf("%d", &F[i]);
    }
    for(i=0;i<K;i++) {
        scanf("%d", &C[i]);
    }
 
    int s=0;
    F[0]=0;
    for(int j=0;j<K;j++) {
        int W = C[j];           
        memset(X,0,sizeof(X));
        for (i = 0; i <= N; i++) {
            for (int w = 0; w <= W; w++) {
               if (i==0 || w==0)
                   X[i][w] = 0;
               else if (F[i-1] <= w)
                     X[i][w] = max(F[i-1] + X[i-1][w-F[i-1]],  X[i-1][w]);
               else
                     X[i][w] = X[i-1][w];
            }
        }
        s+=X[N][W];
        i=N; int w = W;
        printf("%d %d\n", j,X[N][W]); 
        while(i>0){          
            if(F[i-1]<=w&&X[i][w] - X[i-1][w-F[i-1]] == F[i-1]) {
                printf("apaga %d-.%d\n", i, F[i-1]); 
                w = w-F[i-1];
                F[i-1] = 100;
                i--;
            } else i--;
        }
    }
    printf("%d\n",s);
    return 0;
}