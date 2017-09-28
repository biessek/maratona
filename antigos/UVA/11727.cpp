#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int t,a,b,c,i;
    scanf("%d", &t);
    for(i=1;i<=t;i++) {
        scanf("%d %d %d", &a, &b, &c);
        if((a>=b&&a<=c)||(a>=c&&a<=b)) printf("Case %d: %d\n",i,a);
        else if((b>=a&&b<=c)||(b>=c&&b<=a)) printf("Case %d: %d\n",i,b);
        else printf("Case %d: %d\n",i,c);        
    }

    return 0;
}
