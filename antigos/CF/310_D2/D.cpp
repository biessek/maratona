#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct esp {
    unsigned long long i, j;
} gap[200001];

struct pont {
    unsigned long long i, j;
} b[200001];
bool us[200001];

bool comp(esp &a,esp &b) {
    return a.i<b.i;
}
    
bool compb(pont &a,pont &b) {
    return a.i<b.i;
}

int main() {
    int n, m, i, g; 
    unsigned long long l, r, r2, l2;
    scanf("%d %d", &n, &m);
    g=0;
    for(i=0;i<n;i++) {
        if(i>0) {
            scanf("%llu %llu", &r2, &l2);                    
            gap[g].i=l2-r;
            gap[g++].j=r2-l;
            r=r2;l=l2;
        } else
            scanf("%llu %llu", &r, &l);
    }
    sort(gap,gap+g, comp);
    for(i=0;i<m;i++) {
        scanf("%llu", &b[i].i);  b[i].j=i;      
        us[i]=false;
    }
    sort(b,b+m, compb);

    g--;
    for(i=m-1;i>=0&&g>=0;i--) {
        if(b[i].i<=gap[g].i && b[i].i >= gap[g].j) {
            us[i]=true;
            g--;
        }
    }
    if(g<0) {
        puts("Yes");
        for(i=0;i<m;i++) {
            if(us[i]) printf("%d ",b[i].j+1);
        }        
    }
    else puts("No");

   
    return 0;
}
