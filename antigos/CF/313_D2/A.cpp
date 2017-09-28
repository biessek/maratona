#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n, men=10000000, num;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &num);
        men=min(men,num);
    }
    if(men > 1)
        puts("1");
    else 
        puts("-1");
    return 0;
}
