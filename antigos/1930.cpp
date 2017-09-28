#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> ip;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MAX 10100
#define INF 1000000000
int C, V;

vii G[MAX];
int dist[MAX][2];

void dik() {
	for(int i=0;i<MAX;i++) dist[i][0]=dist[i][1]=INF;
	priority_queue<pair<ii,int>,vector<pair<ii,int> > ,greater<pair<ii,int> > > pq;
	pq.push(ip(ii(0,1),0));
	dist[1][0]=0;
	while(!pq.empty()) {
		ip p = pq.top(); pq.pop();
		int u = p.first.second; 
		int d = p.first.first; 
		int k = p.second; 
		int t= G[u].size();
		for(int i=0;i<t;i++) {
			ii f = G[u][i];
			int uu = f.second; 
			int dd = f.first; 
			
			if(dist[u][k]+dd < dist[uu][!k]) {
				dist[uu][!k] = dist[u][k]+dd;
				pq.push(ip(ii(dist[uu][!k],uu),!k));
			}
		}
	}	
}

int main() {
	int a,b,c;
	scanf("%d %d", &C, &V);
	while(V--) {
		scanf("%d %d %d",&a, &b, &c);
		G[a].push_back(ii(c,b));
		G[b].push_back(ii(c,a));
	}
	dik();
	if(dist[C][0] == INF) 
		puts("-1");
	else
		printf("%d\n",dist[C][0]);
	
 	return 0;
}