#include <cstdio>

char game[200];
int main() {
    int i, pt, r;
    char c, n, n2;
    while(gets(game) && game[0] != 'G') {
        pt=0;
        r=1;
        for(i=0;game[i];) {
            c = game[i];
            if(c != 'X') {
                n  = game[i+2];
                if(n=='/') {
                    if(r <= 10) {
                        pt+=10; 
                        n2  = game[i+4];
                        if(n2=='X') pt+=10;
                        else pt+=n2-'0';
                    }
                    r++;
                    i+=4;
                } else {
                    pt+= c-'0'+n-'0';
                    r++;
                    i+=4;
                }
            } else {
                if(r<=10) {
                    pt+=10;
                    n  = game[i+2];
                    n2 = game[i+4];
                    if(n2 == '/') pt+=10;
                    else if(n2 == 'X') pt+=20;                            
                    else {
                        pt+= n2-'0';
                        if(n=='X') pt+=10;
                        else
                        pt+= n-'0';
                    }
                    i+=2;
                } else break;
                r++;                
            }    
            if(r > 10) break;
        }
        printf("%d\n", pt);
    }
}
