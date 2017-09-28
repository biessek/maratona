#include <cstdio>

int out[10][10];
char T[10][10];
int n;
void inc(int i, int j) {
    if(i-1>=0) {
        out[i-1][j]++;
        if(j-1>=0)
            out[i-1][j-1]++;
        if(j+1<n)
            out[i-1][j+1]++;
    } 
    if(i+1<n) {
        out[i+1][j]++;
        if(j-1>=0)
            out[i+1][j-1]++;
        if(j+1<n)
            out[i+1][j+1]++;
    } 
    if(j-1>=0)
        out[i][j-1]++;
    if(j+1<n)
        out[i][j+1]++;
     

}

int main() {
    int i, j, t;
    char c;
    bool f=false;
    bool cp;
    scanf("%d", &t);
    while(t--) {
        if(f) puts("");
        f=true;
        scanf(" %d", &n);
        for(i=0;i<n;i++) 
            for(j=0;j<n;j++) out[i][j]=0;
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                scanf(" %c", &c);    
                if(c=='*') { 
                    inc(i,j);
                    out[i][j] = 200;
                }
            }
        }

        cp = false;
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                scanf(" %c", &T[i][j]);    
                if(out[i][j] >= 200 && T[i][j]=='x') {
                    cp = true;
                }
            }
        }
        
        for(i=0;i<n;i++) {
            if(cp&&out[i][0] >= 200)
                putchar('*');
            else if(T[i][0]=='x')
                printf("%c",out[i][0]+'0');
            else
                putchar('.');
            for(j=1;j<n;j++) {
                if(cp&&out[i][j] >= 200)
                    putchar('*');
                else if(T[i][j]=='x')
                    printf("%c",out[i][j]+'0');
                else
                    putchar('.');
            } puts("");
        }
    }    
    return 0;
}
