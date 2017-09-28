#include <cstdio>
#include <cmath>
using namespace std;

int a,b,c,d,n,i, p, j, k;
long double lis[1001], price[1001], maximo;

const long  double EPS=1e-6;
inline int cmp(long double x, long double y = 0, long double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
    
    lis[0]=price[0]=maximo=0;
    for(k=1;k<=n;k++) {
        price[k] = p * (sin(a*k+b)+cos(c*k+d)+2);        
    }
    for(i=0;i<=n;i++) { lis[i]=0;}
    
    for(i=1;i<=n;i++) {
        for(j=0;j<i;j++) {
            if(price[j] > price[i]) {
                if(cmp(lis[i], lis[j] + (price[j]-price[i])) < 0)
                    lis[i]=lis[j] + (price[j]-price[i]);
            }
        }
        if(cmp(maximo, lis[i]) < 0) {
            maximo = lis[i];
        }
    }
    if(cmp(0.0,maximo)==0)
        puts("0.00");
    else
        printf("%Llf\n",maximo);

    return 0;
}
