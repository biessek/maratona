#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int> ii;
vector<int> G[51];
int V;
int p;
vector<ii> E;
ii removida;

void dfs(int v) {
	V |= 1 << v;
	int t = G[v].size();
	for(int i=0;i<t;i++) {
		if(removida == ii(v,G[v][i])||removida == ii(G[v][i],v)) continue;
		if(!(V & (1 << G[v][i]))) dfs(G[v][i]); 
	}
}
int main() {
	int c, i, a, b;
while(scanf("%d%d",&c,&p) != EOF) {
	for(i=0;i<=c;i++) { 
		  G[i].clear();		 
	}
	V = 0;
	E.clear();
	int t = 0;
	for(i=0;i<p;i++) {
		scanf("%d %d", &a, &b); a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		E.push_back(ii(a,b));
	}
	t = p;
	for(i=0;i<t; i++) {
		removida = E[i]; 
		V=0;
		dfs(0);	
		if(V == ((1 << c) - 1)) p--;
	}
	
	printf("%d\n", p);
}
return 0;
}