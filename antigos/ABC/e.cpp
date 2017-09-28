#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    long long  n, maxx=0, f, u, ac;
    scanf("%lli", &n); 
    if(n==0) { puts("0"); return 0; }

    n--;
    scanf("%lli", &f); u=f;
    while (n--) {    
        scanf("%lli", &ac); 
        maxx = max(maxx, u-f);        
        f = min(f,ac);            
        u=ac;
    }    
        maxx = max(maxx, u-f);        
    printf("%lli\n",maxx);
    return 0;
}


