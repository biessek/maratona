#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int f[1001];

int main() {
    int i, n, num, m;
    while(scanf("%d", &n) && n) {
        for(i=0;i<=n;i++) {
            f[i]=0;
        }
        for(i=0;i<n;i++) {
            scanf("%d", &num);
            f[num]++;
        }
        m=-1;
        for(i=0;i<n;i++) {
            m = max(m,f[i]);
        }
        printf("%d\n", m);
    }

    return 0;
}
