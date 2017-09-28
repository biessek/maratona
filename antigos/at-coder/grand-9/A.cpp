#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int main(){
  ull n, q, h, s, d;
  scanf("%llu %llu %llu %llu", &q, &h, &s, &d);
  scanf("%llu", &n);
  h = min(h, 2*q);
  s = min(s, h*2);
  d = min(d, s*2);
  if(n&1) {
    printf("%llu\n", n>1?min(((n-1)>>1)*d+s, n*s) : s);
  } else {
    printf("%llu\n", (n>>1)*d);
  }
  return 0;
}

// 20 41  80
// .25 .50 1
