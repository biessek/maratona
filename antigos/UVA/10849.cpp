#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int C, N, t, r,c, rd,cd, pl, pld, pc, pcd;
    scanf("%d", &C);
    while(C--) {
        scanf("%d", &t);
        scanf("%d", &N);
        while(t--) {
            scanf("%d %d %d %d", &r, &c, &rd, &cd);
            rd--; cd--; r--; c--;
            pl  = r % 2;
            pld = rd % 2;
            pc  = c % 2;
            pcd = cd % 2;
            if(r==rd&&c==cd) puts("0");
            else if((pl==pc && pld==pcd)||(pl!=pc && pld!=pcd)) {
                if(abs(r-rd) == abs(c-cd)) puts("1");
                else puts("2");
            } else 
                puts("no move");       
        }
    }

    return 0;
}
