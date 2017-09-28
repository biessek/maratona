#include<cstdio>

char b[10][13];
int ib[10][10];
int main() {
    int i, j, r, c, p=1, idx, ii;
    while(scanf("%d", &r) && r) {
        scanf("%d", &c);
        
        for(i=0;i<r;i++) {
            scanf(" %s", b[i]);
        }        
        
        idx=1;
        for(i=0;i<r;i++) 
            for(j=0;j<c;j++) ib[i][j]=0;
        
        for(i=0;i<r;i++) {
            for(j=0;j<c;j++) {
                if(b[i][j] != '*' && (j==0 || i==0 || b[i][j-1] == '*' || b[i-1][j] == '*')) {
                    ib[i][j]=idx++;
                }
            }
        }
        if(p>1) puts("");
        printf("puzzle #%d:\n", p++);
        
        puts("Across");        
        for(i=0;i<r;i++) {
            for(j=0;j<c;j++) {
                if(ib[i][j] != 0) {
                    printf("%3d.", ib[i][j]);
                    while(j<c&& b[i][j] != '*') putchar(b[i][j++]);
                    puts("");
                }
            }
        }

        puts("Down");        
        for(i=0;i<r;i++) {
            for(j=0;j<c;j++) {
                if(ib[i][j] != 0 && (i==0 || b[i-1][j] == '*')) {
                    printf("%3d.", ib[i][j]);
                    ii=i;
                    while(ii<r&& b[ii][j] != '*') putchar(b[ii++][j]);
                    puts("");
                }
            }
        }
    }    

    return 0;
}
