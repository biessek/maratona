#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int  a, b, t;
    int d=0;
    scanf("%d %d", &t, &b); 
    if(b==0) { puts("0"); return 0; }
    a=0;
    t*=100; b*=100;
    
    while (a<b) {    
        d++;
        a+=t;
        if(a>=b) break;
        a-=(t/2);
    }    
    printf("%d\n",d);
    return 0;
}


