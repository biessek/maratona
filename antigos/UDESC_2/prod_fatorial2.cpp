#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define ULL unsigned long long 
int tam[3];
map<int,int> fat[3];
int prim[400], qtp;
bool ehp[2502];

void criv() {
    for(int i = 2;i<=2501;i++) {ehp[i]=true;}
    
    ehp[0]=ehp[1]=false;
    qtp=1; prim[0]=2;
    for(int i = 2;i<=2501;i++) {
        if(ehp[i]) {
            for(j=i*i;j<=2501;j++) {
                ehp[j]=false;
            }
            prim[qtp++]=i;
        }
    }
    
}


long long ep(int n, int p) {
    long long r=1;
    while(p) {
        if(p&1) { r*=n;}
        p>=1; 
        n*=n;
    }
    return r;
}

int main() {
    int T,j,k, a, ct[3][2502];
    int equal, eq[3], mdesc;
    ULL p[3];
    criv();
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {        
        for(j=0;j<3;j++) {
            scanf("%d", &tam[j]);            
            memset(ct[j],0,sizeof(ct[j]));
            fat[j].clear();
        }        

        for(j=0;j<3;j++) {
            for(k=0;k<tam[j];k++) {
                scanf("%d", &a);
                ct[j][a]++;
            }
        }        

        eq[0]=eq[1]=eq[2]=1;
        
        for(j=2;j<=2501;j++) {
            if(ct[0][j]&&ct[1][j]&&ct[2][j]) {
                mdesc = min(min(ct[0][j],ct[1][j]),ct[2][j]);
                ct[0][j]-=mdesc;
                ct[1][j]-=mdesc;
                ct[2][j]-=mdesc;        
            }
            for(k=0;k<qtp;k++) {
                fat[0][prim[k]]+=(ct[0][j] * fat[j][prim[k]]);
                fat[1][prim[k]]+=(ct[1][j] * fat[j][prim[k]]);
                fat[2][prim[k]]+=(ct[2][j] * fat[j][prim[k]]);
                if(fat[0][prim[k]]&&fat[1][prim[k]]&&fat[2][prim[k]]) {
                    mdesc = min(min(fat[2][prim[k]],fat[1][prim[k]]),fat[0][prim[k]]);
                    fat[2][prim[k]]-=mdesc;
                    fat[1][prim[k]]-=mdesc;
                    fat[0][prim[k]]-=mdesc;
                }
            }
        }
        for(k=0;k<qtp;k++) {
            if(eq[0]) {
                if(fat[1][prim[k]]!=fat[0][prim[k]]) eq[0] = 0;
            } 
            if(eq[1]) {
                if(fat[2][prim[k]]!=fat[0][prim[k]]) eq[1] = 0;
            } 
            if(eq[2]) {
                if(fat[2][prim[k]]!=fat[1][prim[k]]) eq[2] = 0;
            } 

            p[0] *= ep(prim[k],fat[0][prim[k]]);
            p[1] *= ep(prim[k],fat[0][prim[k]]);
            p[2] *= ep(prim[k],fat[0][prim[k]]);
            
        }
        if(eq[0]||eq[1]||eq[2]) puts("EMPATARAM");
        else {
            printf("M\n");
        }
    }

    return 0;
}
