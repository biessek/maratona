#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAX = 100001;

bool checkn(ll n) {
  if(n==0 || n == 1) return false;
  if( n == 2) return true;
  ll d=ll(ceil(sqrt(n)));
  while(d > 1) {
    if(n % d == 0) {
      return false;
    }
    d--;
  }
  return true;
}

int main(){
  ll n, d;
  while(scanf("%lli", &n) != EOF) {
    bool ediv = checkn(n);
    bool ehn;
    if(ediv) {
      ehn = true;
      while(ehn && n>=10) {
        ehn = ehn && checkn(n%ll(10));
        n /=10;
      }
      ehn = ehn && checkn(n);
    }
    if(ediv && ehn) puts("Super");
    else if(ediv) puts("Primo");
    else puts("Nada");
  }
  return 0;
}
