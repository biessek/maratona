#include <cstdio>
#include <algorithm>
using namespace std;

int M[10][10];
int c;

int main() {
    char p;
    int m, n, t;
    scanf("%d\n", &t);
    while(t--) {
        scanf("%c %d %d\n", &p, &m, &n);
        if(p=='r') printf("%d\n", min(m,n));
        else if(p=='k') printf("%d\n", ((m*n+1)>>1));
        else if(p=='Q') printf("%d\n", min(m,n));
        else printf("%d\n",((m+1)>>1)*((n+1)>>1));
        
    }

    return 0;
}
