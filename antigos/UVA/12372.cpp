#include <cstdio>

int main() {
    int T, i, a, b, c;
    scanf("%d", &T);
    for(i=1;i<=T;i++) {
        printf("Case %d: ",i);
        scanf("%d %d %d", &a, &b, &c);
        if(a<=20&&b<=20&&c<=20) puts("good");
        else puts("bad");
    }
    return 0;
}
