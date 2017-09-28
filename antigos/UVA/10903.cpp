#include <cstdio>

int pp[100];
int pl[100];

int main() {
    int n, k, p1, p2, g, i;    
    bool pf=false;
    char m1[10], m2[10];
    while(scanf("%d %d", &n, &k) && n) {
        if(pf) puts("");
        pf=true;
        for(i=0;i<n;i++) pp[i]=pl[i]=0;
        g = (k * n * (n-1))/2;
        while(g--) {
            scanf("%d %s %d %s", &p1, m1, &p2, m2);
            if(m1[0] == 'r' && m2[0] == 's') {
                pp[(p1 - 1) % n]++; 
                pl[(p2 - 1) % n]++; 
            }
            else if(m1[0] == 's' && m2[0] == 'p') {
                pp[(p1 - 1) % n]++; 
                pl[(p2 - 1) % n]++; 
            }
            else if(m1[0] == 'p' && m2[0] == 'r') {
                pp[(p1 - 1) % n]++; 
                pl[(p2 - 1) % n]++; 
            }
            else if(m2[0] == 'r' && m1[0] == 's') {
                pp[(p2 - 1) % n]++; 
                pl[(p1 - 1) % n]++; 
            }
            else if(m2[0] == 's' && m1[0] == 'p') {
                pp[(p2 - 1) % n]++; 
                pl[(p1 - 1) % n]++; 
            }
            else if(m2[0] == 'p' && m1[0] == 'r') {
                pp[(p2 - 1) % n]++; 
                pl[(p1 - 1) % n]++; 
            }
        }
        for(i=0;i<n;i++) {
            if(pp[i]+pl[i]==0) puts("-");
            else
            printf("%.3lf\n", pp[i] / double(pp[i]+pl[i]));
        }
    }
    
    return 0;
}
