
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

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

const int MAX = 100005;

ll dp[MAX];
ll last[MAX];

bool pal(int h, int m) {
  int dh1 = (h/10) % 10;
  int dh2 = h%10;
  int dm1 = (m/10) % 10;
  int dm2 = m%10;
  return dh1 == dm2 && dh2 == dm1;
}

int main(){
  int h, m;
  scanf("%d:%d", &h, &m);
  int c=0;
  while(!pal(h,m)) {
    m++;
    if(m==60) {
      h++;
      if(h==24) h=0;
      m=0;
    }
    c++;
  }
  printf("%d\n", c);

  return 0;
}
