#include <cstdio>

int n;
int b[5][5];

bool cabo() {
    int i, j;
    for(i=0;i<5;i++) {
        for(j=0;j<5 && b[i][j]==0;j++);
        if(j==5) return true;
    }
    for(i=0;i<5;i++) {
        for(j=0;j<5 && b[j][i]==0;j++);
        if(j==5) return true;
    }

    for(i=j=0;i<5&&j<5&&b[i][j]==0;i++,j++);
    if(i==5) return true;

    for(i=0,j=4;i<5&&j>=0&&b[i][j]==0;i++,j--);
    if(i==5) return true;

    return false;
}

int main() {
    int i, j, bn;
    scanf("%d", &n);
    while(n--) {
        for(i=0;i<5;i++) {
            for(j=0;j<5;j++) {
                if(i==2&&j==2) continue;
                scanf("%d", &b[i][j]);        
            }
        }
        b[2][2] = 0;
        int w=-1;;
        for(i=1;i<=75;i++) {
            scanf("%d", &bn);
            if(w==-1) {
                for(int k=0;k<5;k++) {
                    for(j=0;j<5;j++) {
                        if(b[k][j] == bn) {b[k][j] = 0; break;}
                    }
                }
                if(cabo()) {
                    w=i;
                }        
            }
        }
        printf("BINGO after %d numbers announced\n", w);
    }
    return 0;
}
