#include<vector>
#include<algorithm>
#include<cstdio>
#include<bitset>
using namespace std;
typedef vector<int> vi;
bool loop;
#define MAXN 10100
#define VISITANDO 2
#define VISITADO 1
#define DESCONHECIDO 0

int V[MAXN]; // status do vertice na visita
vector<int> G[MAXN]; // grafo / lista de adjacencias

bool temloop(int v) {
	V[v]=VISITANDO; // inicia a visita
	int t = G[v].size();

	for(int i=0;i<t;i++) {
		if(V[G[v][i]] == DESCONHECIDO) {
			if(temloop(G[v][i])) // se tem loop num filho 				
				return true;     // retorna true				
			// senao tiver loop n retorna nada, 
			// deixa pro próximo filho(próximo iteração do for)
		} else if(V[G[v][i]] == VISITANDO)
			return true; // isto é um loope. (tenta visitar um vértice
						 // em aberto).
	}

	V[v]=VISITADO;// terminou de visitar

	return false;
}

int main() {
	int T, N, M, a, b, i;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &M);
		
		for(i=1;i<=N;i++) {
			G[i].clear();
			V[i]=DESCONHECIDO;
		}

		while(M--) {
			scanf("%d %d", &a, &b);
			G[b].push_back(a);
		}

		for( i=1;i<=N;i++) {
			if(V[i] == DESCONHECIDO) 
				if(temloop(i)) break;	
		}
		if(i > N) {
			puts("NAO");
		} else {
			puts("SIM");
		}
	}
	return 0;
}
