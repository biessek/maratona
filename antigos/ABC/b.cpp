#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    unsigned long long a,b;
    scanf("%llu %llu", &a, &b); 
    bool f=false;
    while (b--) {    
        if (f) putchar(' ');
        printf("%llu", a);
        f=true;
        a*=10;
    }    
    puts("");
    return 0;
}


