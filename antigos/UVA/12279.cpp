#include <cstdio>

int main() {
    int n, i, s, e, t=1;
    while(scanf("%d", &n) && n) {
        s=0;
        for(i=0;i<n;i++) {
            scanf("%d", &e);
            s+=(e>0)?1 : -1;
        }
        printf("Case %d: %d\n",t++, s);
    }

    return 0;
}
