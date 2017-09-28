#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

ll id[100010];
int main() {
	ll n,m;
	ll f[100010];
	ll b[100010];
	set<ll> F;

	scanf("%lli %lli", &n, &m);
	int r = 0;
	bool end=false;
	for(ll i = 0; i < n; i++)  { scanf("%lli", &f[i]); id[f[i]] = i+1;}			
	sort(f,f+n);
	for(ll i = 0; i < m; i++)  {
		scanf("%lli", &b[i]);
		ll up = upper_bound(f,f+n,b[i])-f;
		ll low = lower_bound(f,f+n,b[i])-f;		
		ll c = up - low;
		if(!end) {
			if(c == 1) continue;
			if(!c) { end = true; r=3;}
			else r = 2;
		}
	}
	if(r == 3) puts("Impossible");
	else if(r == 2) puts("Ambiguity");
	else {
		puts("Possible");
		printf("%lli", id[b[0]]);
		for(ll i = 1; i < m; i++)  {
			printf(" %lli", id[b[i]]);		
		}
	
	}

	
	return 0;
}
