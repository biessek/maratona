#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;
typedef struct { int S, R;} card;
char D;
char deal() {
    if(D=='N') return 'E';
    if(D=='E') return 'S';
    if(D=='S') return 'W';
    if(D=='W') return 'N';
}
struct hand {
    card h[13];      
};
map<char,hand> hands;
map<char,int> hs;

bool cr( char a,  char b) {
    if(a>='2' && a<='9' && b>='2' && b<='9') return a< b;
    if(a>='2' && a<='9') return true;
    if(b>='2' && b<='9') return false;
    if(a=='T'&&b!='T') return true;
    if(a=='J' && b != 'T') return true;
    if(a=='Q' && b != 'T' && b!='J') return true;
    if(a=='K' && b != 'T' && b!='J' && b!='Q') return true;
    
    return false;
}

bool comp(const card &a,const card &b) {
    if(a.S==b.S) return cr(a.R,b.R);

    if(a.S == 'C') return true;
    if(a.S == 'D' && b.S != 'C') return true;
    if(a.S == 'S' && b.S != 'C'&& b.S != 'D') return true;
        
    return false;
}

int main() {
    char deck[180];
    int i,c;
    card at;
    while(scanf("%c\n", &D) && D != '#') {
        D=deal();
        hands.clear();
        hs.clear();
        scanf("%s\n%s\n",deck,deck+52);

        for(i=0;i<52;i++) {
            at.S = deck[i*2];   
            at.R = deck[i*2+1];   
            hands[D].h[hs[D]++]=at;    
            D=deal();           
        }
        sort(hands['N'].h,hands['N'].h+13,comp);
        sort(hands['S'].h,hands['S'].h+13,comp);
        sort(hands['W'].h,hands['W'].h+13,comp);
        sort(hands['E'].h,hands['E'].h+13,comp);
        printf("S:");
        for(i=0;i<13;i++)
            printf(" %c%c",hands['S'].h[i].S,hands['S'].h[i].R); puts("");
        printf("W:");
        for(i=0;i<13;i++)
            printf(" %c%c",hands['W'].h[i].S,hands['W'].h[i].R); puts("");
        printf("N:");
        for(i=0;i<13;i++)
            printf(" %c%c",hands['N'].h[i].S,hands['N'].h[i].R); puts("");
        printf("E:");
        for(i=0;i<13;i++)
            printf(" %c%c",hands['E'].h[i].S,hands['E'].h[i].R); puts("");
    }

    return 0;
}
