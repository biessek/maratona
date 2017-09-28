
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

const int MAX = 200005;
int bitt[MAX];
int bitt2[MAX];

void up1(int i, int v) {
  for(; i<MAX; i += (i & -i)) {
      bitt[i]+=v;
  }
}
void up2(int i, int v) {
  for(; i<MAX; i += (i & -i)) {
      bitt2[i]+=v;
  }
}

void update(int l, int r, int v) {
  up1(l, v);
  up1(r+1,-v);
  up2(l,v*(l-1));
  up2(r+1, -v * r);
}

int query1(int r) {
  int sum = 0;
  for(; r>0;r -= (r & -r)) {
    sum += bitt[r];
  }
  return sum;
}

int query2(int r) {
  int sum = 0;
  for(; r>0;r -= (r & -r)) {
    sum += bitt2[r];
  }
  return sum;
}

int qq(int r) {
  return query1(r) * r - query2(r);
}

int qqq(int l, int r) {
  return qq(r) - qq(l-1);
}

int main(){
  fill(bitt,bitt+MAX, 0);
  fill(bitt2,bitt2+MAX, 0);
  int n, k, q, l, r, i;
  scanf("%d %d %d", &n, &k, &q);
  for(int i=0; i<n;i++) {
    scanf("%d %d", &l, &r);
    update(l, r, 1);
  }

  rep(i, 1, MAX) {
    int qt = qqq(i, i);
    if(qt < k) {
      update(i, i, -qt);
    } else {
      update(i, i, -qt);
      update(i, i, 1);      
    }
  }
  for(int i=0; i<q;i++) {
    scanf("%d %d", &l, &r);
    printf("%d\n", qqq(l, r));
  }
  return 0;
}
