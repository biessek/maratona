#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> ii;

struct line{
	int k, b;
} l[100100];

bool cmp(const line &a, const line &b) {
	return a.k==b.k? a.b<b.b : a.k<b.k;
}

int main() {
	int N, i;	
	int x1, x2;
	
	scanf("%d", &N);
	scanf(" %d %d", &x1, &x2);
	for(i=0;i<N;i++) {
		scanf(" %d %d", &l[i].k, &l[i].b);
	}

	sort(l,l+N,cmp);
	while(x1<x2) {
		double xl = (x1+x2) / 2.;
		double y1 = l[0].k*xl+l[0].b;
		for(i=1;i<N;i++) {
			double yll = l[i].k*xl+l[i].b;
			if(fabs(yll-y1) < 1e-8) break;				
		}
		if(i!=N) break;
		else x1=int(ceil(xl));
	}
	if(x1==x2) puts("No");
	else puts("Yes");

	return 0;
}