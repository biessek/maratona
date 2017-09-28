#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int a1x, a1y, a2x, a2y, a3y, a3x;
    scanf("%d %d", &a1x, &a1y);
    scanf("%d %d", &a2x, &a2y);
    scanf("%d %d", &a3x, &a3y);

    if((a2x + a3x <= a1x && max(a2y,a3y) <= a1y) ||
       (a2y + a3x <= a1x && max(a2x,a3y) <= a1y) ||
       (a2x + a3y <= a1x && max(a2y,a3x) <= a1y) ||
       (a2y + a3y <= a1x && max(a2x,a3x) <= a1y) ||
       (a2x + a3x <= a1y && max(a2y,a3y) <= a1x) ||
       (a2y + a3x <= a1y && max(a2x,a3y) <= a1x) ||
       (a2x + a3y <= a1y && max(a2y,a3x) <= a1x) ||
       (a2y + a3y <= a1y && max(a2x,a3x) <= a1x))

       puts("YES");
    else
       puts("NO");
        
    return 0;
}
