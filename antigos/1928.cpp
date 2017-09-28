#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
#define MAXN 50100
#define MAXL 20

int N, A, B;
int P[MAXN];
int P2[MAXN];
vi G[MAXN];
vi pai(MAXN);
vector<long long> num(MAXN);

void dfs(int s) {
	int qt = G[s].size();
	for(int i=0;i<qt;i++) {
		if(G[s][i]&&num[G[s][i]] == -1) {			
			pai[G[s][i]] = s;
			num[G[s][i]] = num[s]+1;
			dfs(G[s][i]);
		}
	}
}	

int L[MAXN][MAXL];

void memoL() {
	int i, j;
   
  
    for (i = 0; i <= N; i++)
        for (j = 0; 1 << j <= N; j++)
			L[i][j] = -1;
		
	//the first ancestor of every node i is T[i]
      for (i = 1; i <= N; i++)
          L[i][0] = pai[i];
	  
	  //bottom up dynamic programing
      for (j = 1; 1 << j <= N; j++)
         for (i = 1; i <= N; i++)
             if (L[i][j - 1] != -1)
                 L[i][j] = L[L[i][j - 1]][j - 1];
}

int lca(int p, int q) {	
	int log, i;

	//if p is situated on a higher level than q then we swap them
	if (num[p] < num[q])
		swap(p,q);

	//we compute the value of [log(L[p)]
	for (log = 1; 1 << log <= num[p]; log++);
		log--;

	//we find the ancestor of node p situated on the same level
	//with q using the values in P
	for (i = log; i >= 0; i--)
		if (num[p] - (1 << i) >= num[q])
			p = L[p][i];

	if (p == q)
		return p;

	//we compute LCA(p, q) using the values in P
	  for (i = log; i >= 0; i--)
		  if (L[p][i] != -1 && L[p][i] != L[q][i])
			  p = L[p][i], q = L[q][i];

	  return pai[p];
}

int main() {
	int c,i;
    scanf("%d", &N);
    fill(P,P+MAXN,-1);
    for(i=1;i<=N;i++) {
        scanf("%d", &c);
        if(P[c] != -1) 
			P2[c] = i; 
        else 
            P[c] = i;
    }
    for(i=1;i<N;i++) {
        scanf("%d%d", &A, &B);
        G[A].push_back(B);       
        G[B].push_back(A);       
    }
    fill(num.begin(),num.end(),-1);
	num[1]=0;
	num[0]=0;	
	pai[1] = -1;
	
	puts("af");
	dfs(1);
	puts("af");
	memoL();
	
    long long NN = N >> 1; 
	long long sum=0;
for(i=1;i<=NN;i++) {
		sum += num[P[i]]+num[P2[i]] - 2*num[lca(P[i],P2[i])];		
    } 
    printf("%lli\n", sum);

    return 0;
}
