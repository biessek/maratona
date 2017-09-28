#include <cstdio>

char b[9][9];
bool pl=false;
int cw, cb;

int movi[] = {0, 0,1,-1,-1,-1,  1, 1};
int movj[] = {1,-1,0, 0,-1, 1, -1, 1};

bool mval(int i, int j, char p) {
    if(b[i][j] != '-') return false;
    int ii, jj, kj;
    ii=i;
    char sp;
    bool valido ;
    for(kj=0;kj<8;kj++) {
        valido=false;
        sp = p =='W'? 'B' : 'W';    
        ii=i+movi[kj];
        jj=j+movj[kj];
        if(ii<=8 && ii>=1 && jj<=8 && jj>=1) {
            if(b[ii][jj]==sp) {
                valido = true;
            }
            for(ii+=movi[kj], jj+=movj[kj];valido&&ii<=8 && ii>=1 && jj<=8 && jj>=1 && b[ii][jj]==sp; ii+=movi[kj],jj+=movj[kj]);
            if(valido&&ii<=8 && ii>=1 && jj<=8 && jj>=1 && b[ii][jj]==p) {
                return true;
            }            
        }
    }
    return false;
}

char sp(char cp) {return cp == 'W'? 'B' : 'W';}

bool listm(char p,bool sprint=true) {
    int i,j;    
    bool print=false;
    for(i=1;i<=8;i++) {
        for(j=1;j<=8;j++) {
            if(mval(i,j,p)) {
                if(sprint) {
                    if(print) putchar(' ');
                    printf("(%d,%d)", i, j);
                    print=true;
                }
                if(!sprint) return true;
            }
        }
    }
    return print;
}

void putp(int i,int j, char p) {
    int ii,jj, ki, kj;
    char sp; 
    b[i][j] = p;
    if(p=='W') cw++;
    else cb++;
    for(kj=0;kj<8;kj++) {
        bool valido=false;
        sp = p =='W'? 'B' : 'W';    
        ii=i+movi[kj];
        jj=j+movj[kj];
        if(ii<=8 && ii>=1 && jj<=8 && jj>=1) {
            if(b[ii][jj]==sp) {
                valido = true;
            }
            for(ii+=movi[kj], jj+=movj[kj];valido&&ii<=8 && ii>=1 && jj<=8 && jj>=1 && b[ii][jj]==sp; ii+=movi[kj],jj+=movj[kj]);
            if(valido&&ii<=8 && ii>=1 && jj<=8 && jj>=1 && b[ii][jj]==p) {
                for(ii-=movi[kj], jj-=movj[kj];valido&&ii<=8 && ii>=1 && jj<=8 && jj>=1 && b[ii][jj]==sp; ii-=movi[kj],jj-=movj[kj]) {
                    b[ii][jj] = p;
                    if(p=='W') {cw++; cb--;}
                    else {cb++; cw--;}
                }
            }
        }
    }
        
}

int main() {
    int g, i, j, c;
    char cp, row, col;
    scanf("%d", &g);
    bool cpwl,cpbl;
    while(g--) {
        if(pl) puts("");
        pl=true;
        cw=cb=0;
        for(i=1;i<=8;i++) {
            for(j=1;j<=8;j++) {
                scanf(" %c", &b[i][j]);
                cw+=(b[i][j]=='W');
                cb+=(b[i][j]=='B');
            }
        }
        scanf(" %c", &cp);
        while(scanf(" %c", &c) && c!= 'Q') {
            if(c=='L') {
                if(!listm(cp)) puts("No legal move.");
                else puts("");
            } else if(c=='M') {
                scanf("%c%c", &row,&col);
                i=row - '0'; j = col - '0';
                if(!listm(cp,false)) {
                    cp = sp(cp);                    
                }
                putp(i,j,cp);            
                printf("Black - %2d White - %2d\n",cb,cw);        
                cp = sp(cp);                                    
            } 
        }
        for(i=1;i<=8;i++) {
            for(j=1;j<=8;j++) {
                printf("%c",b[i][j]);
            } puts("");
        }       
    }

    return 0;
}
