#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int k, x, y, xq, yq;

    while(scanf("%d", &k) && k) {
        scanf("%d %d", &x, &y);
        while(k--) {
            scanf("%d %d", &xq, &yq);
            if(xq==x||yq==y) puts("divisa");
            else if(xq > x) {
                if(yq>y) puts("NE");
                else puts("SE");
            }
            else {
                if(yq>y) puts("NO");
                else puts("SO");
            }            
        }
    }

    return 0;
}
