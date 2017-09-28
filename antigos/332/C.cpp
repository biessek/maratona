#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
#define MAXN 100005;
ll sl[200010];
ll sm[200010];

ll h[100010];

void up(int i, int v) {
	ll x=i+MAXN;
	for(sl[x]=sm[x]=v;x>1;x>>=1){
		sl[x>>1] = min(sl[x],sl[x^1]);
		sm[x>>1] = max(sl[x],sl[x^1]);
	}
}
int ql(int i, int j) {
	ll x=i+MAXN;
	ll y=j+MAXN;
	ll r=2000000;

	for(;x<y;x>>=1,y>>=1){
		if (x&1) r = min(r,sl[x++]);
    	if (y&1) r = min(r,sl[--y]);	
	}
	return r;
}
int qm(int i, int j) {
	ll x=i+MAXN;
	ll y=j+MAXN;
	ll r=0;

	for(;x<y;x>=1,y>=1){
		if (x&1) r = max(r,sm[x++]);
    	if (y&1) r = max(r,sm[--y]);	
	}
	return r;
}


int main() {
	ll n;
	scanf("%lli", &n);
	memset(sl,0,sizeof(sl));
	memset(sm,0,sizeof(sm));

	for(ll i = 0; i < n; i++) {
		scanf("%lli", &h[i]);
		up(i,h[i]);
	}
	ll l = 1;
	ll r = n;
	ll last=-1;
	while(l < r) {
		ll x = l + ((r-l) >> 1);
		
		ll qtb = n/x;	
		if(n%x == 0 ) {
			ll antmb, bl;		
			for(bl=0;bl<qtb;bl++) {
				ll minb = ql(bl*x,bl*x+x);
				ll maxb = ql(bl*x,bl*x+x);
				if(bl > 0 && minb < antmb) {
					break;
				}
				antmb = maxb;
			}
			if(bl == qtb) {
				last=qtb;
				l = x+1;
			} else r = x;
		} else l = x+1;

	}
	if(last==-1) printf("%lli\n", n);
	else printf("%lli\n", last);
	return 0;
}
