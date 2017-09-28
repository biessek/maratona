#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
typedef struct {char S,N;} card; 
int n,i, pt[4], j, win; 
card manilha;
map<char,int> cartas;
map<char,int> cs;
char nome[4][30];
card jog[4];
int pr[4];

int ganha() {
    int w=-1;
    int ctm=0; bool m[4];
    for(int i=0;i<4;i++) {
        m[i]=cartas[jog[i].N] == cartas[manilha.N] + 1 || (cartas[jog[i].N] == 1  && 10 == cartas[manilha.N]);
        if(m[i]) ctm++;
    }
    if(ctm > 0) {
        
        for(int i=0;i<4;i++) {
            if(m[i] && (w==-1 || (cs[jog[i].S] > cs[jog[w].S]))) {
                w = i;
            }
        }
    }
    if(w!=-1) return w;

    for(int i=0;i<4;i++) {
        if(w==-1 || (cartas[jog[i].N] > cartas[jog[w].N])) {
            w = i;
        }
    }    

    return w;
}

int main() {
    scanf("%d %c%c\n", &n, &manilha.N, &manilha.S);
    cs.clear(); cartas.clear();

    cs['D'] = 1;
    cs['S'] = 2;
    cs['H'] = 3;
    cs['C'] = 4;
    cartas['4']=1;
    cartas['5']=2;
    cartas['6']=3;
    cartas['7']=4;
    cartas['Q']=5;
    cartas['J']=6;
    cartas['K']=7;
    cartas['A']=8;
    cartas['2']=9;
    cartas['3']=10;
    for(i=0;i<4;i++) {
        scanf("%s %d\n", nome[i], &pt[i]);        
        pr[i]=0;    
    }   
    while(n--) {
        for(i=0;i<4;i++) {
            scanf(" %c%c ", &jog[i].N,&jog[i].S);

        }   
            win = ganha();
            if(win!=-1) pr[win]++;
    }
    for(i=0;i<4;i++) {
        pr[i]=abs(pt[i]-pr[i]);
    }
    j=0;
    for(i=1;i<4;i++) {
        if(pr[j]>pr[i]) j=i;
    }    
    bool d=false;
    for(i=0;i<4;i++) {
        if(j!= i && pr[j] == pr[i]) d=true;
    }
    if(d) puts("*");
    else {
        printf("%s\n", nome[j]);
    }
    return 0;
}
