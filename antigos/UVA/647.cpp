#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int th[1001];
int b[101], pp[6];
int cp[6];
int P;
int next(int p) {
    if(b[pp[p]] == 1001) return p;

    p = (p+1) % P;
    while(!cp[p]){ cp[p] = 1; p = (p+1) % P;}
    return p;
}

int main() {
    int p, t, it=0, cls, cle, le;
    while(scanf("%d", &t) && t) th[it++]=t;

    while(scanf("%d", &P) && P) {
        memset(b,0,sizeof(b));
        memset(pp,0,sizeof(pp));
        memset(cp,1,sizeof(cp));
        
        while(scanf("%d %d", &cls, &cle) && cls) {
            b[cls] = cle;       
        }

        while(scanf("%d", &le) && le) {
            b[abs(le)] = le > 0? 1001 : -1001;
        }

        p = 0;
        int w = -1;        
        int r = 0;
        while(r < it) {
            pp[p] += th[r];
            if(pp[p] == 100) {
                w = p;
                break;
            }
            if(pp[p] > 100) {
                pp[p] -= th[r];
            } else if(b[pp[p]] != 0 && b[pp[p]] != 1001 && b[pp[p]] != -1001) {                
                pp[p] = b[pp[p]];
                if(b[pp[p]] == -1001)
                    cp[p] = 0;
            } else if(b[pp[p]] == -1001)
                cp[p] = 0;

            p = next(p);    
            r++;
        }
        printf("%d\n", w+1);
    }
    

    return 0;
}
