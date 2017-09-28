#include <cstdio>
#include <math.h>
#include <cstdlib>

int main() {
    int a,b, r;
    scanf("%d %d", &a, &b);
    if(a==0) {puts("0 0"); return 0;}
    if(b==0) {printf("0 %d",a); return 0;}
    for(r=0;r<=1000;r++) {
        if((abs(a-r) % b)==0) break;
    }
    printf("%d %d\n", (a-r)/b, r);
    return 0;
}
