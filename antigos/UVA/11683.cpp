#include<cstdio>

int main() {
    int A, B, x, ant, res;

    while(scanf("%d %d", &A, &B) == 2 && (A|B)) {
        ant=-1; res=0;
        while(B--) {
            scanf("%d", &x);
            if(ant!=-1) {
                res+=x>=ant?(x-ant):0;
            }
            ant=x;
        }
        printf("%d\n",res+A-ant);
    }
    
    return 0;
}
