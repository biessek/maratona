#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAX = 1000000;
int main(){
  ll l, r, x, y, k;
  ll i;
  scanf("%I64d %I64d %I64d %I64d %I64d", &l, &r, &x, &y, &k);
  for(i = x; i <= y;i++) {
    if(k*i >= l && k*i<=r) break;
  }
  if(i <= y) puts("YES");
  else puts("NO");
  return 0;
}
