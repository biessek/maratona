#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, c, a[200005];
    double r,l, w;
    double mb,mg;

    scanf("%d %lf", &n, &w);
    mg=mb=1e9 * 1.;
    for(int i=0;i<n*2;i++) {
        scanf("%d", &a[i]);
    }    
    sort(a,a+2*n);
    mg=a[0]; mb=a[n];
    mb=min(mb,mg*2.0);
    r=((w/n)/3.) * 2.;
    r=min(double(mb),r);
    
    printf("%.10lf\n",r*n+n*r/2.);
    return 0;
}
