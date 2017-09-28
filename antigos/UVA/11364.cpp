#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int t, n, i, x[20], s;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i=0;i<n;i++) {
            scanf("%d", &x[i]);
        }
        sort(x,x+n);
        s=0;
        for(i=1;i<n;i++) {
            s+=x[i]-x[i-1];    
        }        
        printf("%d\n",s*2);
    }

    return 0;
}
