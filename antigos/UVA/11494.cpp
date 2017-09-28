#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int X,Y,XX,YY;
    while(scanf("%d %d %d %d", &X,&Y, &XX, &YY) && X) {
        if(X==XX && Y == YY) puts("0");
        else if(abs(X-XX)==abs(Y-YY)) puts("1");
        else if(X==XX || Y==YY) puts("1");
        else puts("2");
    }
    return 0;
}
