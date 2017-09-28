#include<cstdio>
#include<vector>
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
const int V = 250100;
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

	int N, M;
char MM[510][510];

bool cango(ii a) {
	if(a.first < 0 || a.first == N || a.second < 0 || a.second == M) return false;
	int i = a.first;
	int j = a.second;
	if(MM[i][j] == '#') return false;

	return true;
}

int custo (ii a) {
	if(a.first < 0 || a.first == N || a.second < 0 || a.second == M) return INF;
	int i = a.first;
	int j = a.second;
	if(MM[i][j] == '#') return INF;

	if(MM[i][j] >= '1' &&  MM[i][j] <= '9') return MM[i][j] - '0';

	return 0;
}
int disk(ii s, ii d) {
	map<ii,int> dist;	
	priority_queue<uii, vector<uii>, greater<uii> > pq;
	dist[s] = 0; // INF = 1B to avoid overflow
	pq.push(uii(0,s));
	while(!pq.empty()) {
		uii u = pq.top(); pq.pop();
		if(u.first > dist[u.second]) continue;

		for(int i=0;i<4;i++) {
			ii go = ii(u.second.first+di[i],u.second.second+dj[i]);

			if(cango(go) && (dist.find(go) == dist.end() || dist[go] > dist[u.second] + custo(go))) {
				dist[go] = dist[u.second] + custo(go);
				pq.push(uii(dist[u.second] + custo(go), go));
			}
		}		
	}
	if(dist.find(d) == dist.end()) return INF;
	return dist[d];
}


int main() {
	int i,j;
	ii s, d;
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++) {
		for(j=0;j<M;j++) {
			scanf(" %c", &MM[i][j]);
			if(MM[i][j] == 'H')	s = ii(i,j);
			else if(MM[i][j] == 'E') d = ii(i,j);
		}
	}
	int dd = disk(s,d);
	if(dd == INF) {
		printf("ARTSKJID\n");	
	} else {
		printf("%d\n", dd);	
	}
	
	return 0;
}
