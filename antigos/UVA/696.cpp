#include <cstdio>
#include <cmath>
#include <algorithm>

int calc(int n, int m) {
//    printf("%d %d\n", n,m);
    if(n==1||m==1) {
        return n*m;
    } else if(n==2||m==2) {
        if(m<n) std::swap(n,m);

        return m<=4? 4 : (m%4==0? (m / 4) << 2  : ((m / 4) << 2) + calc(2,(m%4)));
    } 
    return int(ceil((n*m)/2.));

}


int main() {
    int n,m, c;
    while(scanf("%d %d", &n, &m) && n) {
        printf("%d knights may be placed on a %d row %d column board.\n",calc(n,m), n, m);
    }
    return 0;
}
