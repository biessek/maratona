#include <cstdio>

int main() {
    int N, t, n, w, s, e, b, a;
    char  dir[50];
    while(scanf("%d", &N) && N) {
        t = 1; 
        n = 2; 
        w = 3;
        e = 4;
        b = 6;
        s = 5;
        while(N--) {
            scanf(" %s", dir);
            if(dir[0] == 'n') {
                a = n;
                n = t;
                t = s; 
                s = b;
                b = a;
            } else if(dir[0] == 's') {
                a = t;
                t = n;
                n = b; 
                b = s;
                s = a;
            } else if(dir[0] == 'e') {
                a = t;
                t = w;
                w = b; 
                b = e;
                e = a;
            } else if(dir[0] == 'w') {
                a = t;
                t = e;
                e = b; 
                b = w;
                w = a;
            }
        }
        printf("%d\n", t);
    }    
    return 0;
}
