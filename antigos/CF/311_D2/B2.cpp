#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

const double EPS = 1e-10;

int main() {
    int n, w, i;
    int a[200005];
    scanf("%d %d", &n, &w);
    for(i=0;i<2*n;i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a,a+n*2);
    double l=0,r=a[0]*1.;
    double x;
    double mwb = a[n];
    double mwg = a[0];
    
    while(r-l>=EPS) {
        x=(l+r)/2.;
        if(mwb>=x*2 && mwg>=x && 3*n*x <=w) l=x;
        else r=x;
    }
    printf("%.10lf\n",x*(n*3.));
    
    return 0;
}
