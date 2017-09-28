#include <cstdio>
#include <cstring>

int p[1000000];
int t[101];
int main() {
    int T, a, b, c, i, st, en, v;
    bool end;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &a, &b, &c);
        for(i=0;i<a;i++) p[i]=1;
        for(i=0;i<=100;i++) t[i]=-1;
        for(i=0;i<b;i++) {
            scanf("%d %d", &st, &en);
            t[st]=en;
        }
        end=false;       
        for(i=0;i<c;i++) {
            v = (i%a);
            scanf("%d", &en);            
            if(!end) {
                p[v]+=en;
                if(p[v] >= 100) {
                    end=true;
                } 
                while(!end && t[p[v]] !=-1) {
                    p[v]=t[p[v]];
                    if(p[v] >= 100) {
                        end=true;
                    } 
                }
            }
        }
        for(i=0;i<a;i++) {
            printf("Position of player %d is %d.\n",i+1, p[i]);
        }
   }
    return 0;
}
