#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

#define ON 2
#define VISITED 1
#define UNVISITED 0
#define MAXN 10100
#define MAXM 30100

using namespace std;

vector< vector<int> > doc(MAXN);
vector<int> v;

bool dfs(int u) {
	v[u] = ON;
	int t = doc[u].size();
	for(int i = 0; i < t; i++){
		if(v[doc[u][i]]==ON)return true;
		if(v[doc[u][i]]==UNVISITED) return dfs(doc[u][i]);
	}
	v[u] = VISITED;
	return false;
}

int main() {
	bool loop;
	int t, i, j, n, m , a, b;
	scanf("%d", & t);
	for(i = 0; i < t; i++) {	
		scanf("%d %d", & n, & m);
		doc.assign(n+1, vector<int>());
		v.assign(n+1, UNVISITED);
		//v[0] = VISITED;
		for(j = 1; j <= m; j++) {
			scanf("%d %d", & a, & b);
			v[a] = UNVISITED;
			doc[a].push_back(b);
		}
		loop = false;
		for(j=1;j<=n;j++){
			if(dfs(j)){
				loop = true;
				break;
			}
		}
		printf("%s\n", loop ? "SIM" : "NAO");
	}
	return 0;
}