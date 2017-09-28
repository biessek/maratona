#include <cstdio>

int conts[10];
int main() {
    int N, s[1000], g[1000], cs, cw, d=1, i;
    bool br;
    while(scanf("%d", &N) && N) {
        
        for(i=0;i<N;i++) {
            scanf("%d", &s[i]); 
        }
        printf("Game %d:\n",d++);
        while(true) {
            for(i=0;i<10;i++) conts[i]=0;
            for(i=0;i<N;i++) {
                conts[s[i]]++;
            }
            br=false;
            for(i=0;i<N;i++) {
                scanf("%d", &g[i]);
                br |= g[i]==0;
            }
            if(br) break;
            cs=cw=0;
            for(i=0;i<N;i++) {
                if(g[i]==s[i]) { g[i]=0; cs++; conts[s[i]]--;}
            }
            for(i=0;i<N;i++) {
                if(g[i] && conts[g[i]]>0) { 
                    conts[g[i]]--;                                
                    cw++;
                }
            }
            printf("    (%d,%d)\n",cs,cw);
        }        
    }
    return 0;
}
