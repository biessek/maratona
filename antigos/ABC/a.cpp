#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int a,b;
    scanf("%d %d", &a, &b); 
        if(a>b) swap(a,b);
        for(;a<=b;a++)
            printf("%d ",a);
            puts("");
    
    return 0;
}


