#include <cstdio>
#include <cstring>
#include <cmath>

int N;
int b[10][10];
int p, desti;
int ki[] = {-1, 1, 0, 0};
int kj[] = { 0, 0,-1, 1};



int defr(int i) {    
    if(i<=3) return 1;
    if(i<=6) return 2;
    if(i<=13) return 3;
    if(i<=20) return 4;
    if(i<=27) return 5;
    if(i<=30) return 6;
    if(i<=33) return 7;
}

int defc(int i) {    
    if(i==7||i==14||i==21) return 1;
    if(i==8||i==15||i==22) return 2;
    if(i==1||i==4||i==9||i==16||i==23||i==28||i==31) return 3;
    if(i==2||i==5||i==10||i==17||i==24||i==29||i==32) return 4;
    if(i==3||i==6||i==11||i==18||i==25||i==30||i==33) return 5;
    if(i==12||i==19||i==26) return 6;
    if(i==13||i==20||i==27) return 7;
}

int defi(int i, int j) {
    if(i == 1) { if(j==3) return 1; if(j==4) return 2; if(j==5) return 3;}
    if(i == 2) { if(j==3) return 4; if(j==4) return 5; if(j==5) return 6;}
    if(i == 3) { if(j<=7) return 6+j;  }
    if(i == 4) { if(j<=7) return 13+j; }
    if(i == 5) { if(j<=7) return 20+j; }
    if(i == 6) { if(j==3) return 28; if(j==4) return 29; if(j==5) return 30;}
    if(i == 7) { if(j==3) return 31; if(j==4) return 32; if(j==5) return 33; } 

    return 0; 
}


int mort(int i, int j, int di, int dj) {
   int m=0; int inc;
   if(i==di) {
        inc = dj > j? 1 : -1;
        while(j != dj) {
            m++;
            j+=inc;       
        }
    } else if(j==dj) {
        inc = di > i? 1 : -1;
        while(i != di) {
            m++;
            i+=inc;       
        }
    }
    return m - 1;     
}

int dest(int i, int j) {
    int ii,jj, p, d=-1, c;
    for(int k=0;k<4;k++) {
        c=0;
        for(ii=i+ki[k],jj=j+kj[k];c<1&&ii<=7&&ii>=1&&jj<=7&&jj>=1 && b[ii][jj] == 1;ii+=ki[k],jj+=kj[k],c++);
        if(ii>0&&jj>0&&ii<8&&jj<8 && b[ii][jj] == 0 && c==1) {
            p = defi(ii,jj);
            if(p > 0 && p>=d) {
                d = p;
            }        
        }
    }    
    return d;
}

int nm() {
    int n;
    int i, j, dp, cp, db;
    db=n=-1;
    for(i=1;i<=7;i++) 
        for(j=1;j<=7;j++) {
            if(b[i][j] == 1) {
                if(b[i-1][j] == 1 ||
                   b[i+1][j] == 1 ||
                   b[i][j+1] == 1 ||
                   b[i][j-1] == 1) {
                   cp = defi(i,j);
                   if(cp > 0) {
                       dp = dest(i,j);
                       if(dp > 0) {                             
                            if(n==-1 || dp >= db) {
                                 n  = cp;
                                 db = dp;
                            }       
                       }
                   }             
                }
            }
        }
    desti = db;    
    return n;
}

int main() {
    int i, j, pt, pos, di, dj, inc;
    scanf("%d", &N);
    puts("HI Q OUTPUT");
    while(N--) {
        memset(b,0,sizeof(b));
        while(scanf("%d", &p) && p) {
            i = defr(p);
            j = defc(p);
            b[i][j]=1;    
        }
    
        while((pos = nm()) != -1) {             
            i = defr(pos); j = defc(pos);
            di = defr(desti); dj = defc(desti); 
            if(i==di) {
                inc = dj > j? 1 : -1;
                while(j != dj) {
                    b[i][j] = 0;                        
                    j+=inc;       
                }
                b[i][j] = 1;                                        
            } else {
                inc = di > i? 1 : -1;
                while(i != di) {
                    b[i][j] = 0;                        
                    i+=inc;       
                }
                b[i][j] = 1;                                        
            }
 
        }
        for(pt=0,i=1;i<=7;i++)
            for(j=1;j<=7;j++) 
                if(b[i][j] == 1) {
                    pt+= defi(i,j);
                }

        printf("%d\n",pt);        
            
    }
    puts("END OF OUTPUT");
 
}
