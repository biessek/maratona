#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, i, j, j2;
    int c[100001];
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &c[i]);
    }
    for(i=0;i<n;i++) {
        j = i==0? n-1 : i-1;
        printf("%d %d\n", min(abs(c[i]-c[i+1==n?0:i+1]), abs(c[i]-c[j])),
                max(abs(c[i]-c[0]), abs(c[i]-c[n-1]))
        );
    }
    

    return 0;
}
