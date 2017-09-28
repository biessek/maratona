#include <cstdio>
#include <cmath>
#include <cstring>
int numf, res, conts[10], qts, qtw, dig;
char ns[10], ng[10];

void qq(int num) {
    bool f[10];
    int i;
    int s,w;
    sprintf(ns,"%d", numf);    
    sprintf(ng,"%d", num);    
    for(i=0;i<10;i++) {
        conts[i]=0;
        f[i]=false;
    }
    for(i=0;i<dig;i++) {
        conts[ns[i]-'0']++;
    }
    s=w=0;
    for(i=0;i<dig;i++) {
        if(ns[i]==ng[i]) {
            s++;
            conts[ns[i]-'0']--;
            f[i]=true;
        }
    }
    for(i=0;i<dig;i++) {
        if(!f[i] && conts[ng[i]-'0'] > 0) {
            conts[ng[i]-'0']--;
            w++;       
        }
    }
//    printf("%d %d\n",s,w);
    if(qts==s && qtw==w) {
        res++;
    }
}
int main() {
    int N, i,j,k,l,m, ncalc;
    scanf("%d", &N);
    while(N--) {
        res=0;
        scanf("%d %d %d", &numf, &qts, &qtw);
        dig=log10(numf)+1;
        for(i=1;i<=9;i++) {
            for(j=1;j<=9;j++) {
                if(dig == 2) {
                    sprintf(ns,"%d%d",i,j);
                    sscanf(ns,"%d",&ncalc);
                    qq(ncalc);
                } else {
                    for(k=1;k<=9;k++) {
                        if(dig == 3) {
                            sprintf(ns,"%d%d%d",i,j,k);
                            sscanf(ns,"%d",&ncalc);
                            qq(ncalc);
                        } else {
                            for(l=1;l<=9;l++) {
                                if(dig == 4) {
                                    sprintf(ns,"%d%d%d%d",i,j,k,l);
                                    sscanf(ns,"%d",&ncalc);
                                    qq(ncalc);
                                } else {
                                    for(m=1;m<=9;m++) {
                                        sprintf(ns,"%d%d%d%d%d",i,j,k,l,m);
                                        sscanf(ns,"%d",&ncalc);
                                        qq(ncalc);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
