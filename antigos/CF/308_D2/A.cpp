#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n, x1, x2, y1, y2;
    long long sum=0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
        
        sum+= ((abs(y2-y1)+1)*(abs(x2-x1)+1));
    }
    printf("%lli\n",sum);

}
