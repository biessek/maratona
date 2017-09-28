#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int c=1000000000, n;
    long long sum=0;
    scanf("%d", &n);
    while(c>=10) {
        if(n >= c) {
            sum+=(n-c+1)*(floor(log10(c))+1);
            n=n-(n-c)-1;
        }
        c/=10;
    }
    
    printf("%lli\n",sum+n);

}
