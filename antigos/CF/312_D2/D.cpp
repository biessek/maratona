#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct range{
    unsigned long long L,R;
};

inline bool operator<(const range& a,const range& b) {
        return a.L < b.L;
}



set<range> sr;

int main() {
    int h, q, i, ans;
    unsigned long long L, R;
    range r;
    scanf("%d %d", &h, &q);
    r.L=1;
    for(i=1;i<h;i++) r.L <<= 1;

    r.R=(r.L<<1)-1;
    sr.insert(r);
    while(q--) {
        scanf("%d %llu %llu %d", &i, &L, &R, &ans);    
        while(i<h) {
            L <<=1;
        }
    }
    printf("%llu %llu\n", r.L, r.R);
        
    return 0;
}
