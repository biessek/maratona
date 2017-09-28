#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a, ll b) {
  return b==0? a : gcd(b, a%b);
}
const int MAX = 200001;
vi g[MAX];
ll A[MAX];
const int zerado = 1;
ll orig[MAX];
bool V[MAX][2];

void solve() {
  queue<ii> q;
  q.push(ii(0,!zerado));
  while(!q.empty()) {
    ii v = q.front(); q.pop();
    int t = g[v.first].size();
    for(int i = 0;i<t;i++) {
      ll gg = A[v.first];
      if(v.second == zerado) {
        if(!V[g[v.first][i]][!zerado]) {
          A[g[v.first][i]] = gcd(gg,orig[g[v.first][i]]);
          q.push(ii(g[v.first][i], zerado));
          V[g[v.first][i]][!zerado] = true;
        }
      } else {
          A[g[v.first][i]] = max(gg, gcd(gg,orig[g[v.first][i]]));
          if(!V[g[v.first][i]][!zerado])
            q.push(ii(g[v.first][i], !zerado));
          if(!V[g[v.first][i]][zerado])
            q.push(ii(g[v.first][i], zerado));
          V[g[v.first][i]][!zerado] = true;
          V[g[v.first][i]][zerado] = true;
      }
    }
  }
}

int main(){
  int n, x, y;
  scanf("%d", &n);

  for(int i = 1;i<=n;i++) {
    scanf("%I64d", &orig[i]);
    A[i] = 0;
    V[i][0]=V[i][1]=false;
  }
  for(int i = 1;i<n;i++) {
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  A[0] = 0;
  g[0].push_back(1);
  solve();

  printf("%I64d", A[1]);
  for(int i = 2;i<=n;i++) {
    printf(" %I64d", A[i]);
  } puts("");


  return 0;
}
