#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
#define MAXN (int)100100
vector<ULL> st(MAXN * 4);
vector<ULL> lazy(MAXN * 4);

ULL query(int p, int l, int r, int i, int j) {
	if(l > j || r < i) return 0;

	if(lazy[p]!=0) { //need up
		st[p] += (lazy[p] * (r-l+1));
		if(l!=r) {
			lazy[p<<1]+=lazy[p];
			lazy[p<<1|1]+=lazy[p];
		}
		lazy[p]=0;
	}


	if(l>=i && r<=j) {
		return st[p];
	}

	int m = (l+r) >> 1;
	return query(p<<1, l, m,i,j) + query(p<<1|1, m+1, r,i,j);
}

void change(int p, int l, int r, int i, int j, ULL V) {
	if(lazy[p]!=0) { //need up
		st[p] += (lazy[p] * (r-l+1));
		if(l!=r) {
			lazy[p<<1]+=lazy[p];
			lazy[p<<1|1]+=lazy[p];
		}
		lazy[p]=0;
	}
	if(l > j || r < i) return;

	if(l >= i && r <= j) {
		st[p] += (V * (r-l+1));
		if(l!=r) {
			lazy[p<<1]+=V;
			lazy[p<<1|1]+=V;
		}
		return;
	}


	int m = (l+r) >> 1;
	change(p<<1, l, m, i, j, V);
	change(p<<1|1, m+1, r, i,j, V);
	st[p] = st[p<<1] + st[p<<1|1];
}

int main() {
	int N, C, i, p, q, T, op;	
	ULL v;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d",&N, &C);
		st.assign((N+1)*4,0);
		lazy.assign((N+1)*4,0);

		for(i=0;i<C;i++) {
			scanf(" %d", &op);
			if(op == 0) {
				scanf(" %d %d %llu", &p, &q, &v);				
				change(1,0, N-1, p-1,q-1,v);
			} else {
				scanf(" %d %d", &p, &q);								
				printf("%llu\n", query(1, 0, N-1, p-1, q-1));
			}
		}
	}
	return 0;
}