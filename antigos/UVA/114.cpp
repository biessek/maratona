#include <cstdio>

int pin[60][60];
int bp[10000], bc[10000];
int n, m, cw;

void turn(int &d) {d=d-1; if(d==-1) d= 3; }

int sim(int x, int y, int &dir, int &life) {    
 //   printf("%d %d %d %d\n",x,y,dir,life);
    if(life <= 0) return 0;
    
    if(x == 1 || x == n) {// hit wall        
        turn(dir);
        x=x==1? 2 : n-1;
        life=life-cw;
        return sim(x,y,dir,life);
    }
    if(y == 1 || y == m) {// hit wall
        turn(dir);        
        life=life-cw;
        y=y==1? 2 : m-1;
        return sim(x,y,dir,life);
    }
    if(pin[y][x] != 0) {
        life += (bc[pin[y][x]] * -1);
        int p = bp[pin[y][x]];
        
        if(dir==0) x--;                            
        if(dir==1) y--;                            
        if(dir==2) x++;                            
        if(dir==3) y++;                            
        // desfaz ultima andada
        turn(dir);
        return p + sim(x,y,dir,life);
    }
    
    if(life >= 1) {
        life--;
        if(dir == 0) 
            return sim(x+1,y,dir,life);
        if(dir == 1) 
            return sim(x,y+1,dir,life);
        if(dir == 2) 
            return sim(x-1,y,dir,life);
        if(dir == 3) 
            return sim(x,y-1,dir,life);
    }
    return 0;
}

int main() {
    int p, i, j, x, y, dir, life, sum=0;
    scanf("%d %d", &m, &n);
    scanf("%d", &cw);
    scanf("%d", &p);
    for(i=0;i<=m+1;i++) 
        for(j=0;j<=n+1;j++)  pin[i][j]=0;
        
    for(i=1;i<=p;i++) {
        scanf("%d %d %d %d", &x, &y, &bp[i], &bc[i]);            
        pin[y][x] = i;
    }
    while(scanf("%d %d %d %d", &x, &y, &dir, &life) != EOF) {
        int pt = sim(x, y, dir, life);
        printf("%d\n", pt);        
        sum+=pt;
    }
    printf("%d\n", sum);        

    return 0;
}
