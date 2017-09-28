#include <cstdio>
#include <cstring>
#include <cmath>

bool call[100];
int main() {
    int N,B, i, b[100], j, ball, qt;

    while(scanf("%d %d", &N, &B) && N) {
        for(i=0;i<B;i++) {
            scanf("%d", &b[i]);
        }
        for(i=0;i<=N;i++) {
            call[i]=false;
        }
        for(i=0;i<B;i++) {
            for(j=0;j<B;j++) {
                ball=std::abs(b[i]-b[j]);
                call[ball]=true;
            }
        }
        for(i=0;i<=N && call[i];i++);
        if(i>N) puts("Y");
        else puts("N");
        
    }
    return 0;
}
