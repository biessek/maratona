#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

map<string,int> ichoc;
char cchoc[17][3]  = {"","QB", "QM", "QC"
                        ,"RB", "RM", "RC"
                        ,"TB", "TM", "TC", "Q_", "R_", "T_", "_B",  "_M",  "_C",  "__"};
void cc() {
    ichoc["QB"] = 1; ichoc["QM"] = 2; ichoc["QC"] = 3; ichoc["Q_"] = 10;
    ichoc["RB"] = 4; ichoc["RM"] = 5; ichoc["RC"] = 6; ichoc["R_"] = 11;
    ichoc["TB"] = 7; ichoc["TM"] = 8; ichoc["TC"] = 9; ichoc["T_"] = 12;
    ichoc["_B"] = 13; ichoc["_M"] = 14; ichoc["_C"] = 15; ichoc["__"] = 16;
}

int TT[3][3];

int main() {
    int n, i, c, j, k, x, y, li, lj, di, dj;
    char FS[3][3][3];
    int idxc;
    
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        scanf("%d", &c);
        for(j=0;j<3;j++) {
            for(k=0;k<3;k++) {
                TT[j][k] = (1 << 16); // todas as peças podem estar nessa posição '_' em tudo
            }
        }
        
        
        while(c--) {
            scanf("%d %d", &y, &x);
            for(j=0;j<y;j++) {
                for(k=0;k<x;k++) {
                    scanf(" %s ", FS[j][k]);
                }                
            }
            if(y == x && y == 1) continue;

            for(j=0;j<3;j++) {
                for(k=0;k<3;k++) {
                    if(j+y<=3 &&k+x<=3) {
                        printf("ccc %d %d\n",j,k);
                        for(li=0;li<y;li++) {
                            for(lj=0;lj<x;lj++) {
                                idxc = ichoc[string(FS[li][lj])];                           
                                if(strcmp(FS[li][lj], "__")!=0) {
                                    TT[j][k] |= (1 << idxc);
                                    
                                    for(di=0;di<y;di++) {
                                        for(dj=0;dj<x;dj++) {
                                            if(di!=j&&dj!=k) {
                                                TT[j+di][k+dj] &= ~(1 << idxc);
                                            }        
                                        }
                                    }                                
                                }
                            }
                        }         
                    }
                }
            }                        
        }
        
        for(j=0;j<3;j++) {
            for(k=0;k<3;k++) {
                idxc
                if((TT[j][k] >=1&& TT[j][k] <= 9) || TT[j][k] == (1<<16)) printf("%c%c ", cchoc[idxc][0],cchoc[idxc][1]);
                else               printf("pp ");
            }
            puts("");
        }
        
    }
    
    return 0;
}
