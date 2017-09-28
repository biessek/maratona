#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string a, b;
char l[100000];
int c[26];

int main() {
    int t, qt, i, err, ac;
    while(scanf("%d\n", &t) && t != -1) {
        printf("Round %d\n",t);
        scanf("%s\n", l);
        qt=0;
        for(i=0;i<26;i++) c[i]=0;
        for(i=0;l[i];i++) {
            if(c[l[i]-'a']==0) {
                qt++;
                c[l[i]-'a']=1;
            }
        }
        scanf("%s", l);
        err=ac=0;
        for(i=0;ac<qt&&err<7&&l[i];i++) {
            if(c[l[i]-'a']==0) err++;
            else if(c[l[i]-'a']==1) {
                ac++;
                c[l[i]-'a']=2;
            }            
        }
        
        if(err==7) puts("You lose.");
        else if(ac==qt) puts("You win.");
        else puts("You chickened out.");
        
    }
    return 0;
}
