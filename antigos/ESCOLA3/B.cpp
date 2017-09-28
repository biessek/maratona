#include <cstdio>

int main() {
    int n, ia = 1, ialg, alg;
    scanf("%d", &n); 
    scanf("%d", &ialg); 
    for(int i=2;i<=n;i++) {
        scanf("%d", &alg); 
        if(alg<ialg) {
            ia = i;
            ialg = alg;    
        }    
    }
    printf("%d\n",ia);
    return 0;
}
