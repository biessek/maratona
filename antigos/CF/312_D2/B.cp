#include <cstdio>
#include <algorithm>
using namespace std;

struct t{
    int x,a;
    bool g;
} xx[100];

bool comp(const t &a, const t &b) {
    
    return a.x < b.x;
}
int main() {
    int n, cr, xi, i, r, count;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d %d", &xx[i].x, &xx[i].a);        
    }
    sort(xx,xx+n,comp);
    int x =0;
    while(x<n&&xx[x].x < 0) x++;
    cr = n - x;
    r=0;
    if(x<cr) {
        cr=x;
        for(count=0;cr<n&&count<x+1;cr++,count++) r+=xx[cr].a;    
        x--;
        while(x>=0) {
            r+=xx[x].a;
            x--;
        }
    } else {
        count=cr;
        cr=x;
        for(;cr<n;cr++) r+=xx[cr].a;    
        x--;
        while(count>=0&&x>=0) {
            r+=xx[x].a;
            x--; count--;
        }
    }
       
    printf("%d\n", r);
    return 0;
}
