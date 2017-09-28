#include <cstdio>
#include <cstring>
#include <cmath>
    unsigned long long  P, inv;

bool ispal() {
    char p[30];
    int k;
    k=0;
    unsigned long long  PP = P;
    while(PP>=10) {
        p[k++] = '0'+(PP%10);
        PP/=10;
    }
    p[k++] = '0'+(PP%10);
    p[k]='\0';
    sscanf(p,"%lu",&inv);
    return inv == P;    
}

int main() {
    int N, i;
    scanf("%d", &N);
    while(N--) {
        scanf("%llu", &P);
        i=0;
        while(!ispal()) {
            P+=inv;
            i++;
        }
        printf("%d %llu\n", i, P);
    }
    return 0;
}
