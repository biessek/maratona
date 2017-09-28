#include <cstdio>
#include <cstring>

char g[100][104];
char ng[100][104];

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0,-1, 1};

bool mata(char p, char pp) {
    if(p == 'R' && pp == 'S') return true;
    if(p == 'P' && pp == 'R') return true;
    if(p == 'S' && pp == 'P') return true;

    return false;
}


int main() {
    int n, r, c, t,i, j, p, ni, nj;
    bool f=false;
    scanf("%d", &t);
    while(t--) {
        if(f) puts("");
        f=true;
        scanf("%d %d %d", &r, &c, &n);
        for(i=0;i<r;i++) scanf(" %s", g[i]);

        while(n--) {
            memset(ng,'\0', sizeof(ng));
            for(i=0;i<r;i++) {
                for(j=0;j<c;j++) {                    
                    p = g[i][j];  
                    for(int k=0;k<4;k++) {
                        ni = i + dx[k]; nj=j+dy[k];
                        if(ni>=0&&nj>=0&&ni<r&&nj<c) {      
                            if(ng[ni][nj] == '\0') {
                                if(mata(p, g[ni][nj])) {
                                    ng[ni][nj] = p;
                                } else {
                                }
                            }
                        }                        
                    }                      
                    
                }    
            }
            for(i=0;i<r;i++) 
                for(j=0;j<c;j++) if(ng[i][j])               
                    g[i][j] = ng[i][j];            
        }
        for(i=0;i<r;i++) 
            printf("%s\n", g[i]);                            
    }


    return 0;
}
