/*input

*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define fi first
#define se second
#define INF    1<<30
#define NEGINF -(1<<30)
#define LINF   1<<60
#define EPS 1e-10
#define PI 2 * acos(0)
#define NULO -1
#define endl '\n'

const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int cmp(double x, double y = 0, double tol = EPS){ return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

int main(){
  int c, v0, v1, a, l;
  scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);
  int r=0;
  int d=0;
  while(r<c) {
    if(d>=1) {
      v0 = min(v0+a,v1);
      r-=l;
    }
    d++;
    r+=v0;
  }
  printf("%d\n", d);


  return 0;
}
