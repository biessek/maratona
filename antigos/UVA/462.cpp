#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

char ss[] = {'S', 'H', 'D', 'C'};
char cc[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

int main() {
    char s[100], S,R;
    int i, pt, j,m,mj;
    map<char,map<char,int> > suit;
    while(scanf("%[^\n]\n",s) != EOF) {
        pt=0;
        suit.clear();
        
        for(i=0;i<13;i++) {
            R=s[i*3]; S=s[i*3+1];
            if(R=='A') pt+=4;
            else if(R=='K') pt+=3;
            else if(R=='Q') pt+=2;
            else if(R=='J') pt++;
            suit[S][R]++;           
        }
        for(i=0;i<13;i++) {
            R=s[i*3]; S=s[i*3+1];
            if(R=='K') {
                j=suit[S].size();
                if(j-1 == 0) pt--;
            }
            if(R=='Q') {
                j=suit[S].size();
                if(j-1 <= 1) pt--;
            }
            if(R=='J') {
                j=suit[S].size();
                if(j-1 <= 2) pt--;
            }
        }

        if(pt >= 16) {
            bool st=true;
            for(j=0;st&&j<4;j++) {
                i =suit[ss[j]].size();
                st &= (suit[ss[j]]['A'] != 0 || (suit[ss[j]]['K'] != 0 && i>1) || (suit[ss[j]]['Q'] != 0 && i>2));
            }
            if(st) {
                puts("BID NO-TRUMP");                        
                continue;
            }
        }
        
        for(j=0;j<4;j++) {
            i= suit[ss[j]].size();
            if(i == 2) pt++;
            else if(i<=1)pt+=2;
        }

        if(pt<14) puts("PASS");
        else {
            i=0;
            int v;
            m=-1;
            for(j=0;j<4;j++) {
                v=0;
                for(i=0;i<13;i++) {
                    v+=suit[ss[j]][cc[i]];
                }
                if(v>m) {
                    m=v;
                    mj=j;
                }
            }

            printf("BID %c\n", ss[mj]);
        }
        
        
    }


    return 0;
}
