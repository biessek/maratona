#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

char pp[100];
set<string> s;
int main() {
    int p, i, j, t, i2, j2;
    string pl, ps;
    while(scanf(" %s", pp) != EOF) {
        pl = string(pp);
        p=0;
        t=strlen(pp);
        s.clear();
        for(i=0;i<t;i++) {
            for(j=i;j<t;j++) {
                i2=i; j2 = j;
                // comecou um
                while(i2<=j2&&pp[i2]==pp[j2]) { i2++; j2--; }
                if(i2 > j2) {                
                    ps = pl.substr(i,j-i+1);
                    if(s.find(ps) == s.end()) {
                        p++;
                    }
                    s.insert(ps);
                }
            }
            
        }
        
        printf("The string '%s' contains %d palindromes.\n",pp,p);
    }
    
    return 0;
}
