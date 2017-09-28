#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;

ll n;
ll divs=0;
ll i, j;

int main() {
    scanf("%llu", &n);
    
    for (i=2;n>1 && i*i < n; i++) {
        if(n%i==0) {
          divs++;
          while(n%i==0) {
              n/=i;
          }
        }
    }
    if(n!=1) divs++;  // n fatorou até virar primo. ex: 10 = 2 * 5
    if(divs == 0 || divs == 1) puts("0");
    else {
        printf("%llu\n", (1<<divs) - divs - 1);
    }
    
    return 0;	
}