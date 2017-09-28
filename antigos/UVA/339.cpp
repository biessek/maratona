#include <cstdio>
#include <algorithm>
using namespace std;

int g[11][41];
int cp, n, m;

void printg();

bool paint(int i, int j, int p) {
    if(i < 1 || j < 1 || i > n || j > m) return false;
    if(g[i][j] == -1) return false;
    if(g[i][j] != p) return false;

    g[i][j] = -1; 
    cp--;
    
    paint(i-1,j, p);
    paint(i+1,j, p);
    paint(i,j-1, p);
    paint(i,j+1, p);    
    return true;
}


void rem(int i, int j) {
    int p = g[i][j];
    
    g[i][j] = -1; cp--;
    bool pt = false;
    pt |= paint(i-1,j,p);
    pt |= paint(i+1,j,p);
    pt |= paint(i,j-1,p);
    pt |= paint(i,j+1,p);
    if(pt) {
        int jj,ii;
        // tudo pra baixo
        int kk;
        for(jj=1;jj<=m;jj++) {
            for(ii=1;ii<=n;ii++) {
                if(g[ii][jj] == -1) {
                
                    kk = ii+1;
                    while(kk<=n) {
                        if(g[kk][jj]==-1) kk++; 
                        else break;
                    }
                    if(kk<=n ) {
                        swap(g[ii][jj],g[kk][jj]);
                    }
                }                     
            }    
        }
        for(jj=1;jj<=m;jj++) {
            if(g[1][jj] == -1) {
                kk = jj+1;
                while(kk<=m) if(g[1][kk]==-1) kk++; else break;
                
                if(kk<=m) {
                    for(ii=1;ii<=n;ii++) 
                        swap(g[ii][jj],g[ii][kk]);
                }
            }                     
        }    

    } else {
        g[i][j] = p; cp++;
    }
}   

void printg() {
    int ii,jj;
    for(ii=n;ii>=1;ii--) {
        printf("   ");
        for(jj=1;jj<=m;jj++) {
            if(g[ii][jj] == -1)
                printf("  ");
            else
                printf(" %d", g[ii][jj]);
            
        } 
        printf("\n");
    }
}

int main() {
    int i, j, game=1;
    bool w;
    while(scanf("%d %d", &n, &m) && n|m) {
        for(i=1;i<=n;i++) 
            for(j=1;j<=m;j++) 
                scanf("%d", &g[i][j]);                

        w=false;        
        cp = n*m;
        while(scanf("%d %d", &i, &j) && i|j) {
            if(!w) {
                if(i>=1 && i <=n && j>=1 && j<=m) {
                    rem(i,j);
                    if(cp == 0) w= true;
                }
            }
        }
        if(game>1) puts("");
        printf("Grid %d.\n", game++);
        if(w) puts("    Game Won");
        else {
            printg();            
        }

    }      
    return 0;
}
