#include <cstdio>
#include <algorithm>
using namespace std;

char p[5][5];

int main() {
    int i,j, ci, cj, n, pz=1;
    char op;
    bool ok;
    while(scanf("%c", &p[0][0]) && p[0][0] != 'Z') {
        ci=cj=0;
        for(j=1;j<5;j++) {
            scanf("%c", &p[0][j]);
            if(p[0][j]==' ') {
                cj=j;
            }
        }
        getchar();
        
        for(i=1;i<5;i++) {
            for(j=0;j<5;j++) {
                scanf("%c", &p[i][j]);
                if(p[i][j]==' ') {
                    ci=i; cj=j;
                }
            }
            getchar();
        }

		
        ok = true;
        while((op = getchar()) && op != '0') {
            if(op == 'L') {
                n=cj-1;
                ok &= n >=0 && n<=5;
                if(ok)
                	swap(p[ci][cj],p[ci][n]);
                cj--;
            }
            else if(op == 'R') {
                n=cj+1;
                ok &= n >=0 && n<=5;
                if(ok)
                swap(p[ci][cj],p[ci][n]);
                cj++;
            }
            else if(op == 'A') {
                n=ci-1;
                ok &= n >=0 && n<=5;
                if(ok)
                swap(p[ci][cj],p[n][cj]);
                ci--;
            }
            else if(op == 'B') {
                n=ci+1;
                ok &= n >=0 && n<=5;
                if(ok)
                swap(p[ci][cj],p[n][cj]);
                ci++;
            }
        }
        getchar();        
        if(pz>1) puts("");
        printf("Puzzle #%d:\n",pz++);
        if(ok) {
            for(i=0;i<5;i++) {
                printf("%c", p[i][0]);
                for(j=1;j<5;j++) {
                    printf(" %c", p[i][j]);
                } puts("");
            }   
        } else {
            puts("This puzzle has no final configuration.");
        }
        
    }

    return 0;
}
