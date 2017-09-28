#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

set<int> mapa;
int r, op;

int main() {
    int n, i, d, cj, m=0;
    d=0;
    scanf("%d", &n);
    mapa.clear();
    for(i=0;i<n;i++) {
        scanf(" %c %d", &op, &r);        
        if(op=='+') {
            d++;
            m=max(m,d);
            mapa.insert(r);
        } else if(mapa.find(r)==mapa.end()) {
            m++;
        } else {
            mapa.erase(r);
            d--;
        }

    }
       
    printf("%d\n",m);
    

    return 0;
}
