#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef vector<int> vi;
#define MAXV 5100
vi G[MAXV];
vi V(MAXV);
vi P(MAXV);
vi N(MAXV);
int ll, rr;

void dfs(int v, int n=0) {
	V[v]=1;
	int t= G[v].size();
	for(int i =0;i<t;i++) {
		if(!V[G[v][i]]) {
			P[G[v][i]] = v;
			N[G[v][i]] = n+1;
			dfs(G[v][i],n+1);
		}
	}
}
int path[MAXV];
int paux[MAXV];
bool lcaa(int a, int b) {
	int t=0;
	int t2=0;	

	while(N[a] > N[b]) { path[t++]=a; a=P[a]; }		
	while(N[a] < N[b]) { paux[t2++]=b; b=P[b]; }	

	if(a==b) {
		path[t++] = a;		
		for(int j=t2-1;j>=0;j--)
			path[t++]=paux[j];		
	} else {
		while(a!=b) {
			path[t++]=a;
			a=P[a];
			paux[t2++]=b;
			b=P[b];									
		}
		path[t++]=a;
		for(int j=t2-1;j>=0;j--)
			path[t++]=paux[j];		
	}	

	if(t%2==0) {		
		ll = min(path[(t-2)>>1],path[((t-2)>>1)+1]);
		rr = max(path[(t-2)>>1],path[((t-2)>>1)+1]);
	} else {
		ll = path[t>>1];		
	}

	return t&1;
}

int main() {
	int n, i, l, a, b;
	while(scanf("%d", &n) && n) {
		for(i=0;i<=n;i++) G[i].clear();
		for(i=1;i<n;i++) {
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		V.assign(n+1,0);
		N.assign(n+1,-1);
		P[1]=0;
		dfs(1);
		scanf("%d", &l);
		while(l--) {
			scanf("%d %d", &a, &b);
			if(lcaa(a,b)) printf("The fleas meet at %d.\n", ll);			
			else printf("The fleas jump forever between %d and %d.\n", ll, rr);	
		}
	}
	return 0;
}

