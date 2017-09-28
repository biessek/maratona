#include <cstdio>
#include <algorithm>
using namespace std;

int cx[500002];
int main() {
    int n, m, total, idx, i, back;
    scanf("%d %d", &m, &n);
    total = idx =min(m,n) - 1;
    while(idx < m-1) {
        
        for(i=0;i<idx;i++) {
            scanf("%d", &cx[i]);
            cx[i]-=total;        
        }
        
        back=0;
        for(i=idx-1;i>=0;i--) {
            if(cx[i]-back > 0) {
                total+=cx[i]-back;
                back+=(cx[i]-back);
            }
        }
        total += n-1;
        idx+=n-1;
    }
    printf("%d\n", total);
    return 0;
}
