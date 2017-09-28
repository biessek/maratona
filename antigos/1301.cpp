#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN (int)100100
vector<int> st(MAXN >> 1);
int N;
void build() {
	for(int i = N-1;i>0;i--) st[i] = st[i<<1]*st[i<<1|1];
}
int query(int l, int r) {
	int res=1;
	for(l+=N,r+=N;l<r;l>>=1,r>>=1) {
		if(l&1) res *= st[l++];
		if(r&1) res *= st[--r];
	}
	return res;
}

void change(int i, int v) {
	for(st[i+=N]=v;i>1;i>>=1) st[i>>1] = st[i]*st[i^1];
}

int main() {
	int K, i, V, I;
	char op;
	while(scanf("%d%d",&N, &K) != EOF) {
		st.assign(N<<1,1);
		for(i=0;i<N;i++) {
			scanf("%d", &st[N+i]); st[N+i] = st[N+i] > 0? 1 : (st[N+i]<0? -1 : 0);
		}

		build();
		bool some=false;
		for(i=0;i<K;i++) {
			scanf(" %c %d %d", &op, &I, &V);
			if(op == 'C') {
				change(I-1,V > 0? 1 : (V<0? -1 : 0));
			} else {
				some=true;
				int q = query(I-1,V);
				printf("%c",q>0?'+':q<0?'-' : '0');
			}
		}
		if(some) puts("");
	}
	return 0;
}