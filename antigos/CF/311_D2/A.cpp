#include <cstdio>
#include <algorithm>

int main() {
    int n,m1,mx1,m2,mx2,m3,mx3, r1, r2;

    scanf("%d", &n);
    scanf("%d %d", &m1, &mx1);
    scanf("%d %d", &m2, &mx2);
    scanf("%d %d", &m3, &mx3);

    r1=std::min(mx1, n-m2-m3);
    printf("%d", r1);
    n-=r1;
    r2=std::min(mx2, n-m3);
    printf(" %d", r2);
    printf(" %d\n", n-r2);
    

    return 0;
}
