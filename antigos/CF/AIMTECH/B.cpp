#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int cell[50][50];
ll memo[51];

ll expo(ll a, ll b){
  ll result = 1;
  while (b){
    if (b&1){
      result *= a;
    }
    b >>=1 ;
    a *= a;
  }
  return result;
}

int ki[] = {1, 0, -1, 0};
int kj[] = {0, -1, 0, 1};
int n, m;
int d(int i, int j, int c, int dir = -1)  {
  if(i == n||j==m||i<0||j<0) return 0;
  int s = 0;
  if(cell[i][j] == c) {
    s++;
    cell[i][j] = -1;
  }
  if(s == 0) return s + d(i+ki[dir], j+kj[dir], c, dir);
  for(int kk = 0; kk<4; kk++) {
    s += d(i+ki[kk], j+kj[kk], c, kk);
  }
  return s;
}

int main(){

  ll sum=0;
  scanf("%d %d", &n, &m);
  for(int i = 0;i < n; i++) {
    for(int j = 0;j < m; j++) {
      scanf("%d", &cell[i][j]);
    }
  }

  for(int i = 0;i <= 50; i++) {
      memo[i] = expo(2, i) - 1;
  }

  for(int i = 0;i < n; i++) {
    for(int j = 0;j < m; j++) {
      if(cell[i][j] == -1 ) continue;
      sum+=memo[d(i,j,cell[i][j])];
    }
  }
  printf("%I64d\n", sum);
  return 0;
}
