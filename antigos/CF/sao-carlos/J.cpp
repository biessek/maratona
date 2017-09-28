#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool isT(ull a, ull b, ull c) {
  return a+b > c && a+c > b && b+c > a;
}

ull beleza(ull a, ull b, ull c) {
  ull l[3]; l[0] = a; l[1] = b; l[2] = c;
  sort(l, l+3);
  return l[0] + l[1] - l[2];
}

int main(){
  ull a, b;
  ull x,r1,r2;
  scanf("%I64d %I64d", &a, &b);
  r1=r2=0;
  ull l = 2;
  ull r = max(a,b);
  while(l < r) {
    x = l + (r + l) / 2;
    if(isT(a,b,x)) {
      l = x;
      r1 = x;
    } else {
      r = x-1;
    }
  }

  l = max(a,b)+1;
  r = a+b+1;
  while(l < r) {
    x = l + (r + l) / 2;
    if(isT(a,b,x)) {
      r = x-1;
      r2 = x;
    } else {
      l = x;
    }
  }
  if(isT(a,b,r2) && beleza(a,b,r2) > beleza(a,b,r1)) {
    printf("%I64d\n", r2);
  } else {
    printf("%I64d\n", r1);
  }
  return 0;
}
