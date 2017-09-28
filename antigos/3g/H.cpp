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
vector<int> F(110);
vector<int> FF(110);
int picks[110][60];
int main() {
    int N, K, i;
    int C[5];
    scanf("%d %d", &N, &K);
    for(i=0;i<N;i++) {
        scanf("%d", &FF[i]);
    }
    for(i=0;i<K;i++) {
        scanf("%d", &C[i]);
    }
    int ss=0;
    for(int k=0;k<K;k++) {
	    int s=0;
	    F = FF;
	    for(int j=k;;) {
	        int W = C[j];           
	        memset(X,0,sizeof(X));
	        memset(picks,0,sizeof(picks));
	        for (i = 1; i <= N; i++) {
	            for (int w = 0; w <= W; w++) {
	   				picks[i][w] = -1;	               	
                    X[i][w] = X[i-1][w];
	                if (F[i-1] != -1 && F[i-1] <= w && F[i-1] + X[i-1][w-F[i-1]] > X[i][w]) {
	                    X[i][w] = F[i-1] + X[i-1][w-F[i-1]];
	                	picks[i][w] = 1;	               	

	                }
	            }
	        }
	        s+=X[N][W];
	        i=N; int w = W;
	        while(i>0){          
	            if(picks[i][w] == 1) {
	                i--;	                
	                w-=F[i]; F[i]=-1;
	            } else {
	            	i--;
	            }
	        }
			j=(j+1) % K;
	    	if(j==k) break;
	    }
	    ss=max(ss,s);
	}
    printf("%d\n",ss);
    return 0;
}