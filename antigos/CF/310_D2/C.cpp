#include <cstdio>
#include <cstring>
#include <algorithm>


int main() {
    int n, k, m, i,j, c, desc;
    int v;
    bool kw;
    scanf("%d %d", &n, &k);
    if(k==1) { puts("0"); return 0;}
    desc=0;
    c=0;    
    
    while(k--) {
        kw=false;
        scanf("%d", &m);
        for(i=0;i<m;i++) {
            scanf("%d", &v);            
            if(v==i+1) {
                desc++;
                kw=true;
            }
        }
        if(kw) {
            c+= m-desc;
        } else {
            c+= m-1;
        }
    }

    printf("%d\n", c+n-desc);
    return 0;
}
