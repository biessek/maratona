#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define VISITANDO 1
#define VISITADO 2
#define DESCONHECIDO 0
vector<int> G[51];
int V[51];
int P[51];
int p;
void descontaloop(int v) {
}
bool dfs(int v) {
V[v]=VISITANDO;
int t = G[v].size();
bool loop,temloop=false;
for(int i=0;i<t;i++) {
	loop = false;
	if(V[G[v][i]] == DESCONHECIDO && P[v] != G[v][i]) {
		P[G[v][i]]=v;
		loop = dfs(G[v][i]);
	} else if(V[G[v][i]] == VISITANDO && P[v] != G[v][i]) {
		loop = true;
		printf("loop %d %d\n", v, G[v][i]);
		descontaloop(G[v][i]);
	}
	temloop |= loop;
	}
	V[v]=VISITADO;
	return temloop;
}
int main() {
	int c, i, a, b;
while(scanf("%d%d",&c,&p) != EOF) {
	for(i=0;i<=c;i++) { 
		  G[i].clear();
		  V[i]=DESCONHECIDO;
		  P[i]=0;
	}
	for(i=0;i<p;i++) {
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
//         P[0]=-1;
	dfs(1);
	printf("%d\n", p);
}
return 0;
}