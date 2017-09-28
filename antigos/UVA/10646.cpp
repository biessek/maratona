#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct {char N,V; int i; bool ok;} card;

vector<card> p, po;

bool comp(const card &a,const card &b) {
    return a.V < b.V;
}
card h[25];
int main() {
    int t, i, j, q, Y, X, co;
    card c;
    scanf("%d", &t);
    for(i=1;i<=t;i++) {
        p.clear(); po.clear();
        for(j=0;j<52;j++) {
            scanf(" %c%c", &c.V, &c.N);
            p.push_back(c);            
        }        
        q=0;
        while(q<25) {
            h[q++]=p.back(); p.pop_back();
        }

        Y=0;
        for(j=0;j<3;j++) {
            c = p.back(); p.pop_back();
            X = c.V > '9'? 10 : c.V - '0';
            Y+=X;
            co=10-X;    
            while(co>0) {
                p.pop_back(); co--;
            }    
        }
        for(j=q-1;j>=0;j--) { h[j].ok=true; p.push_back(h[j]);}
        printf("Case %d: %c%c\n",i,p[Y-1].V,p[Y-1].N);        
        
    }
    return 0;
}
