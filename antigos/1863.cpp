#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
typedef vector<int> vi;
typedef vector<int> vi;
const int MAXT = 50100;
const int MAXN = 805;
vector<vi> stc(MAXN<<1);

struct sold {      
    int x,y;
    sold() {
        x=y=0;
    }
} S[MAXT];

vi PD(MAXT);    
vi GF[MAXT];    
vi GFF[MAXT];    
vi DG(MAXT,0);
bool calc[MAXT];
vector<bool> V(MAXT);

void set(int x, int y, int v) {
	for(x+=MAXN;x > 0; x>>=1) {
		int yy=y;
		for(stc[x][yy+=MAXN]=v;yy > 1; yy>>=1)	
			stc[x][yy>>1]=max(stc[x][yy],stc[x][yy^1]);
	}
}

int query(int lx, int rx, int ly, int ry) {	
	int res=0;

	for(lx+=MAXN,rx+=MAXN;lx<rx;lx>>=1,rx>>=1) {
		if(lx&1) {
			int ily=ly;
			int iry=ry;
			for(ily+=MAXN,iry+=MAXN;ily<iry;ily>>=1,iry>>=1) {
				if(ily&1) res= max(res, stc[lx][ily++]);
				if(iry&1) res= max(res, stc[lx][--iry]);
			}
			lx++;
		}
		if(rx&1) {
			rx--;
			int ily=ly;
			int iry=ry;
			for(ily+=MAXN,iry+=MAXN;ily<iry;ily>>=1,iry>>=1) {
				if(ily&1) res= max(res, stc[rx][ily++]);
				if(iry&1) res= max(res, stc[rx][--iry]);
			}
		}
	}
	return res;
}

int res;
void dfs(int v) {	
	int t = GF[v].size();
	int u,i;
	int prev = query(0,S[v].x,0,S[v].y);
	PD[v] = max(PD[v], prev+1);
	res = max(res, PD[v]);

	set(S[v].x,S[v].y, PD[v]);
	for(i = 0;i<t;i++) {
		u = GF[v][i];
		dfs(u);			
	}
	set(S[v].x,S[v].y,0);

}

int main() {
	int N, M, a, b, i;
	scanf("%d %d", &N, &M);

	stc.assign(MAXN<<1, vi(MAXN<<1,0));
	PD.assign(MAXT, 0);
	DG.assign(MAXT, 0);

	for(i=1;i<=N;i++) {
		scanf("%d %d", &S[i].x, &S[i].y); S[i].x+=400; S[i].y+=400;
	}

	for(i=0;i<M;i++) {
		scanf("%d %d", &a, &b);
		GF[b].push_back(a);		
	}

	res=0;	
	for(i=1;i<=N;i++) {
		dfs(i);
	}
	printf("%d\n", res);
    return 0;
}