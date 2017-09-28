#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>

char L[10010];
char RL[10010];
char M[100][100];
int len;

void clear() {
    int l, i, k;
    int t=strlen(L);
    for(i=k=0;i<t;i++) {
        if(isalpha(L[i]))
            L[k++] = L[i];
    }
    L[k]='\0';    
    for(i=0;i<k;i++) {
        RL[i]=L[k-i-1];
    }
}

bool isp() {
    int i=0;
    int j= strlen(L)-1;

    while(i<j&&L[i]==L[j]) { i++; j--; }

    return i >= j;
}

bool checkM() {
    int i, j;
    int r = int(sqrt(len));
    for(i=0;i<r;i++) {
        for(j=0;j<r;j++) {
            if(M[i][j] != L[i*r+j]) return false;
        }
    }
    for(i=0;i<r;i++) {
        for(j=0;j<r;j++) {
            if(M[j][i] != L[i*r+j]) return false;
        }
    }

    for(i=r-1;i>=0;i--) {
        for(j=r-1;j>=0;j--) {
            if(M[i][j] != RL[i*r+j]) return false;
        }
    }

    for(i=r-1;i>=0;i--) {
        for(j=r-1;j>=0;j--) {
            if(M[j][i] != RL[i*r+j]) return false;
        }
    }
    return true;
}


int main() {
    int t, i;
    scanf("%d\n", &t);
    for(i=1;i<=t;i++) {
        gets(L);
        printf("Case #%d:\n", i);
        clear();
        if(isp()) {
            len = strlen(L);
            int r = int(sqrt(len));
            if(r*r == len) {
                
                for(int k=0;k<len;k++) {
                    M[k/r][k%r]=L[k];
                }
                if(checkM()) {                    
                    printf("%d\n", r);
                    continue;
                }
            }
        } 

        puts("No magic :(");
        
    }

    return 0;
}
