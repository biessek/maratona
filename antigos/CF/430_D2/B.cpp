#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAX = 1000000;

int main(){
  ll r, d, n, i, sx, sr, sy;
  scanf("%I64d %I64d", &r, &d);
  scanf("%I64d", &n);
  int c = 0;
  for(i = 0;i < n;i++) {
    scanf("%I64d %I64d %I64d", &sx, &sy, &sr);
    ll dc = sx*sx + sy*sy;
    ll r2 = ((r-d) + sr) * ((r-d) + sr);

    if(dc >= r2) {
      ll r1 = (r - sr) * (r - sr);
      ll r2 = (r + sr) * (r + sr);
      if(dc <= r1) {
        c++;
      }
    }
  }
  printf("%d\n", c);

  return 0;
}
