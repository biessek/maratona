#include <cstdio>
#include <cstring>
#include <algorithm>

char T[8][8];
char l[100], p;
int c;

bool dat(int i, int j) {
    if(i>=0&&j>=0&&i<8&&j<8) {
        if(T[i][j]=='.') T[i][j]='*';
        else if(T[i][j]!='*') {
            return true;
        }
        return false;
    }
    return true;
}

void att(int i, int j) {
    char p = T[i][j];
    int ii;
    if(p=='p'||p=='P') {
        dat(p=='p'? i+1:i-1, j+1);
        dat(p=='p'? i+1:i-1, j-1);
    } 
    if(p == 'n' || p == 'N') {
        dat(i-1, j+2);
        dat(i-1, j-2);
        dat(i-2, j+1);
        dat(i-2, j-1);
        dat(i+1, j+2);
        dat(i+1, j-2);
        dat(i+2, j+1);
        dat(i+2, j-1);
    }
    if(p=='b'||p=='B' || p == 'q' || p == 'Q') {
        for(ii=1;i+ii<8&&j+ii<8;ii++)   if(dat(i+ii,j+ii)) break;
        for(ii=1;i-ii>=0&&j+ii<8;ii++)  if(dat(i-ii,j+ii)) break;
        for(ii=1;i-ii>=0&&j-ii>=0;ii++) if(dat(i-ii,j-ii)) break;
        for(ii=1;i+ii<8&&j-ii>=0;ii++)  if(dat(i+ii,j-ii)) break;
    }
    if(p=='r'||p=='R' || p == 'q' || p == 'Q') {
        for(ii=i+1;ii<8;ii++)  if(dat(ii,j)) break;
        for(ii=i-1;ii>=0;ii--) if(dat(ii,j)) break;
        for(ii=j+1;ii<8;ii++)  if(dat(i,ii)) break;
        for(ii=j-1;ii>=0;ii--) if(dat(i,ii)) break;
    } 
    if(p=='k'||p=='K') {
        dat(i-1, j);
        dat(i+1, j);
        dat(i,   j-1);
        dat(i,   j+1);
        dat(i-1, j-1);
        dat(i-1, j+1);
        dat(i+1, j-1);
        dat(i+1, j+1);
    }
    
}

int main() {
    int i,j, k, s, it;
    while(gets(l)) {
        s=strlen(l);   
        c=0;
        for(i=k=j=0;i<s;i++) {
            p=l[i];
            if(j==8) {j==8;j=0; k++;}
            if(p >='1' && p <='8') {
                it=p-'0';
                while(it--) {
                    if(j==8) {j==8;j=0; k++;}   
                    T[k][j++]='.';
                }
            } else if(p!='/') {
                T[k][j++]=p;
            }
        }
        for(i=0;i<8;i++)
            for(j=0;j<8;j++) {
                p=T[i][j];
                if(p!='.' && p != '*') {
                    att(i,j);
                }
            }
        for(i=0;i<8;i++)
            for(j=0;j<8;j++) c+=(T[i][j] == '.');

        printf("%d\n", c);    
    }
    return 0;
}
