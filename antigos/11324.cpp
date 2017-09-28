#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<bitset>
using namespace std;
typedef vector<int> vi;
#define MAXN 1100

int N, T, M;
vi G[MAXN];
vi GT[MAXN];
vi GC[MAXN];
vi CV(MAXN);
vi DP(MAXN);
vi TSC(MAXN);
bitset<MAXN> V;
int scc;
stack<int> st;

void ordem(int v) {
	V[v] = true;
	int t = G[v].size();	
	for(int i=0;i<t;i++) {
		if(!V[G[v][i]])
			ordem(G[v][i]);
	}
	st.push(v);
}

void dfs(int v) {
	V[v] = true;
	CV[v] = scc;
	TSC[scc]++;

	int t = GT[v].size();	
	for(int i=0;i<t;i++) {
		if(!V[GT[v][i]])
			dfs(GT[v][i]);
	}
}

int vai(int v) {
	if(DP[v] != -1) return DP[v];
	int m = 0;

	int t= GC[v].size();
	for(int i =0;i<t;i++) {
		m=max(m,vai(GC[v][i]));
	}
	return (DP[v] = m+TSC[v]);
}

int main() {
	int a, b, i,j;
	scanf("%d", &T);	
	while(T--) {		
		scanf("%d%d", &N, &M);	
		for(i=1;i<=N;i++){ G[i].clear(); GT[i].clear();}

		while(M--) {
			scanf("%d%d", &a, &b);	
			G[a].push_back(b);
		}

		V.reset();
	 	while(!st.empty()) st.pop();

		for(i=1;i<=N;i++) if(!V[i])  ordem(i);


		for(i=1;i<=N;i++) {
			int t = G[i].size();
			for(j = 0;j<t;j++) {
				GT[G[i][j]].push_back(i);
			}
		}

		V.reset();
		scc=0;
		while(!st.empty()) {
			int v = st.top(); st.pop();
			if(!V[v]) {
				TSC[scc]=0;
				GC[scc].clear();
				dfs(v);
				scc++;			
			}
		}

		for(i=1;i<=N;i++) {
			int t = G[i].size();
			for(j=0;j<t;j++) {
				int v = G[i][j];
				if(CV[i]!=CV[v]){
					GC[CV[i]].push_back(CV[v]);
				}
			}
		}
		DP.assign(MAXN,-1);
		int m = 0;
		for(i=0;i<scc;i++) {			
			m=max(m,vai(i));
		}
		printf("%d\n", m);
	}
	return 0;
}