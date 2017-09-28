#include <cstdio>

int out[100][100];
int n,m;
void inc(int i, int j) {
    if(i-1>=0) {
        out[i-1][j]++;
        if(j-1>=0)
            out[i-1][j-1]++;
        if(j+1<m)
            out[i-1][j+1]++;
    } 
    if(i+1<n) {
        out[i+1][j]++;
        if(j-1>=0)
            out[i+1][j-1]++;
        if(j+1<m)
            out[i+1][j+1]++;
    } 
    if(j-1>=0)
        out[i][j-1]++;
    if(j+1<m)
        out[i][j+1]++;
     

}

int main() {
    int i, j, r=1;
    char c;
    while(scanf("%d %d", &n, &m) && n) {
        for(i=0;i<n;i++) 
            for(j=0;j<m;j++) out[i][j]=0;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                scanf(" %c", &c);    
                if(c=='*') { 
                    inc(i,j);
                    out[i][j] = 200;
                }
            }
            getchar();
        }
        if(r>1) puts("");    
        printf("Field #%d:\n", r++);    
        for(i=0;i<n;i++) {
            if(out[i][0] >= 200)
                putchar('*');
            else
                printf("%c",out[i][0]+'0');
            for(j=1;j<m;j++) {
                if(out[i][j] >= 200)
                    putchar('*');
                else
                    printf("%c",out[i][j]+'0');
            } puts("");
        }
    }    
    return 0;
}
