#include <cstdio>
#include <cstring>

int main() {
    int n, t;
    char s[200004], c, p[200004];

    scanf("%d\n", &n);
    scanf("%s", s);
    t=-1;
    for(int i=0;i<n;i++) {
        c=s[i];
        if(t!=-1 && c != p[t]) {
            t--;
        } else p[++t]=c;                
    }
    printf("%d\n", t+1);
    return 0;
}
