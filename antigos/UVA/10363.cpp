#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

char l[3][5];
char win;
int w;
bool wx, wo;

bool acabou() {
    char let[2] = {'X', 'O'};
    int i, j, k;
    w=0;
    wx=wo=false;
    for(i=0;i<2;i++) {
        char p = let[i];

        for(j=0;j<3;j++) {
            int c=0;
            for(k=0;k<3;k++) {
                c+= l[j][k] == p;
            }
            if(c == 3) {
                win=p;
                w++;
                wx|=p=='X';
                wo|=p=='O';
            }
        }
        for(j=0;j<3;j++) {
            int c=0;
            for(k=0;k<3;k++) {
                c+= l[k][j] == p;
            }
            if(c == 3) {
                win=p;
                w++;
                wx|=p=='X';
                wo|=p=='O';
            }
        }
    }
    if(l[0][0] == l[1][1] && l[0][0] == l[2][2]&& (l[0][0] == 'X' || l[0][0] == 'O')) {
        win=l[0][0];
        wx|=win=='X';
        wo|=win=='O';
        w++;
    }
    if(l[0][2] == l[1][1] && l[0][2] == l[2][0]&& (l[0][0] == 'X' || l[0][0] == 'O')) {
        win=l[1][1];
        wx|=win=='X';
        wo|=win=='O';
        w++;
    }

    return w == 1;
}

int main() {
    int N, cx, co, i;
    scanf("%d", &N);
    while(N--) {
        cx=co=0;
        for(i=0;i<3;i++) {    
            scanf(" %s", l[i]);
            co+= l[i][0] == 'O'; co+= l[i][1] == 'O'; co+= l[i][2] == 'O';
            cx+= l[i][0] == 'X'; cx+= l[i][1] == 'X'; cx+= l[i][2] == 'X';
        }

        acabou();

        if(wo && !wx) {
            if(co == cx) puts("yes");
            else puts("no");
        } else if(!wo && wx) {
            if(cx == co + 1) puts("yes");
            else puts("no");
        } else if(!wo && !wx){
            if(cx == co + 1 || cx == co) puts("yes");
            else puts("no");
        } else puts("no");
    }

    return 0;
}
