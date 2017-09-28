#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAXN (int)1100
using namespace std;
typedef vector<int> vi;
int stc[MAXN*3][MAXN*3];
int D, X, Y; 

int gcd(int a, int b) {
    return b==0||a==0?a+b:gcd(b,a%b);
}


bool ok(int lx, int rx, int ly, int ry) {
    int xd = min(abs(lx-X),abs(rx-X));
    int d = D-xd;
    int d2 = D-min(abs(ly-Y),abs(ry-Y));
    return max(abs(ly-Y),abs(ry-Y)) <= d && max(abs(lx-X),abs(rx-X)) <= d2;
}

int query(int x, int y, int d) {
    return qx(1,0, MAXN-1);    
}

int main() {
    int C, i, d, x, y;
    char op;    
    while(scanf("%d",&C) != EOF) {
        memset(stc, 0, sizeof(stc));
         
        for(i=0;i<C;i++) {
            scanf(" %c%*s %d %d %d", &op, &X, &Y, &D);
            X+=500; Y+=500;
            if(op == 'S') {                                                 
                set(x, y, d);
            } else {
                printf("%d\n", query(x, y, d));
            }
        }
    }
     
    return 0;
}