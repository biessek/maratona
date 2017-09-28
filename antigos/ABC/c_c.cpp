#include <cstdio>
 
#include <climits>
 
#include <vector>
 
#include <map>
 
#include <algorithm>
 
using namespace std;
 
int main() {
    int a,b,d=0, t;
 
    scanf("%d %d", &t, &b); 
    a=0;
    while (a<b) {    
        a += t;
        d++;
        if(a>=b)break;
        a-=(t/2);
    }    
    printf("%d\n",d);
 
    return 0;
 
}
