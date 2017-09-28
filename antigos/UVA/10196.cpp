#include <cstdio>
#define WA 2
#define BA 4

char T[8][10];
bool ok;
char p;
int ua[8][8];
int ik[2], jk[2];

bool pw(char p) {
    return p>='A'&&p<='Z';
}
bool mt(char p, char op) {
    return (p>='A'&&p<='Z' && op>='A'&&op<='Z') ||
    (p>='a'&&p<='z' && op>='a'&&op<='z');
}

bool dat(char o, int i, int j) {
    if(i>=0 &&j>=0&&i<8&&j<8) {
        if(T[i][j]!='.') {
            if(!mt(o,T[i][j]))
                ua[i][j]|= pw(o)? WA : BA;
            return false;
        }
        ua[i][j]|= pw(o)? WA : BA;
        return true;
    }
}

bool unda(int k) {
    int i, j;
    i=ik[k];
    j=jk[k];
    return (pw(T[i][j]) && (ua[i][j] & BA)) ||
           (!pw(T[i][j]) && (ua[i][j] & WA));
}
void att(char p,  int i, int j) {
    int ii, jj;
    if(p=='p' || p=='P') {        
        dat(p, p=='P'? i-1 : i+1,j-1);
        dat(p, p=='P'? i-1 : i+1,j+1);
    }
    if(p=='b'||p=='B' || p=='q' || p=='Q') {
        for(ii=1;i+ii<8 && j+ii<8 ;ii++)  if(!dat(p, i+ii, j+ii)) break;
        for(ii=1;i+ii<8 && j-ii>=0;ii++)  if(!dat(p, i+ii, j-ii)) break;
        for(ii=1;i-ii>=0&& j+ii<8 ;ii++)  if(!dat(p, i-ii, j+ii)) break;
        for(ii=1;i-ii>=0&& j-ii>=0;ii++)  if(!dat(p, i-ii, j-ii)) break;
    } 
    if(p=='r'||p=='R' || p=='q' || p=='Q') {
        for(ii=i+1;ii<8;ii++)  if(!dat(p, ii, j)) break;
        for(ii=i-1;ii>=0;ii--) if(!dat(p, ii, j)) break;
        for(jj=j+1;jj<8;jj++)  if(!dat(p, i, jj)) break;
        for(jj=j-1;jj>=0;jj--) if(!dat(p, i, jj)) break;
    }
    if(p=='k'||p=='K') {
        dat(p, i-1,j);
        dat(p, i-1,j+1);
        dat(p, i  ,j+1);
        dat(p, i+1,j+1);
        dat(p, i+1,j);
        dat(p, i+1,j-1);
        dat(p, i  ,j-1);
        dat(p, i-1,j-1);
    }
    if(p=='N'||p=='n') {
        dat(p, i-1,j+2);
        dat(p, i-1,j-2);
        dat(p, i-2,j+1);
        dat(p, i-2,j-1);
        dat(p, i+1,j+2);
        dat(p, i+1,j-2);
        dat(p, i+2,j+1);
        dat(p, i+2,j-1);
    }
}

int main() {
    int i,j, d=1;
    while(true) {
        
        ok=false;
        for(i=0;i<8;i++) {
            scanf(" %s", T[i]);
            for(j=0;!ok&&j<8;j++) {                
                ok|=(T[i][j]!='.');
            }            
        }
        if(!ok) break;
        for(i=0;i<8;i++)
            for(j=0;j<8;j++) ua[i][j]=0;

        for(i=0;i<8;i++) {
            for(j=0;j<8;j++) {                
                p=T[i][j];
                if(p=='k'||p=='K') {
                    if(p=='k') { ik[0]=i; jk[0]=j;}
                    else { ik[1]=i; jk[1]=j;}
                } 
                if(p!='.') {
                    att(p,i,j);        
                }            
            }            
        }

        if(unda(0)) {
            printf("Game #%d: black king is in check.\n", d++);
        } else if(unda(1)) {
            printf("Game #%d: white king is in check.\n", d++);
        } else {
            printf("Game #%d: no king is in check.\n", d++);
        }        
    }
    return 0;
}
