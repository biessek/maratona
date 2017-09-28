#include <cstdio>
#include <set>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX (int) 10000100
#define MAXLC 1010
#define MAXK 6
 
std::vector<bool> bs(MAX);
 
void crivo(int N) {
    bs.assign(MAX,true);
    int m = (int) sqrt(N) + 1;
    bs[0] = bs[1] = false;
    int i,j;
    for(i =2;i<=m;i++)  
        if(bs[i]) {
            for(j=i*i;j<N;j+=i) bs[j]=false; 
        }
}
 
int pd[MAXLC][MAXLC][MAXK];
int M[MAXLC][MAXLC];
int L, C, K;
const int INF = 10000001;
 
bool ehprimo(int n) {
    return bs[n];
}
int res;
 
void pd1() { // modo normal
    int i, j, aux1, aux2;   
 
    for(i=L;i>=1;i--) {
        for(j=1;j<=C;j++) {              
            pd[i][j][0]=0;
            if(M[i][j] < M[i+1][j]) {
                pd[i][j][0] = max(pd[i][j][0],pd[i+1][j][0] + 1);       
            }
            if(M[i][j] < M[i][j-1]) {
                pd[i][j][0] = max(pd[i][j][0],pd[i][j-1][0] + 1);
            }
            res=max(res,pd[i][j][0]);

            for(int k=1;k<=K;k++) {  
                pd[i][j][k]=0;
                aux1=aux2=0;            
 
                if(M[i][j] < M[i+1][j]) 
                    aux1 = pd[i+1][j][k] + 1;                 
                if(ehprimo(M[i+1][j]))
                    aux1 = max(aux1,pd[i+1][j][k-1] + 1);                 
 
                if(M[i][j] < M[i][j-1]) 
                    aux2 = pd[i][j-1][k] + 1;                 
                if(ehprimo(M[i][j-1]))
                    aux2 = max(aux2,pd[i][j-1][k-1] + 1);                 
 
                pd[i][j][k] = max(pd[i][j][k],max(aux1,aux2));                
                res=max(res,pd[i][j][k]);
            }   
            // for(int k=0;k<=K;k++) {  
            //      printf("pd[%d][%d][%d]=%d\n", i,j,k, pd[i][j][k]);
            //  }
        }
    }
}
 
void pd2() { // modo reverso
    int i, j, aux1, aux2;
     
 
    for(i=1;i<=L;i++) {
        for(j=C;j>=1;j--) {              
            pd[i][j][0]=0;
 
            if(M[i][j] < M[i-1][j]) {
                pd[i][j][0] = max(pd[i][j][0],pd[i-1][j][0] + 1);       
            }
            if(M[i][j] < M[i][j+1]) {
                pd[i][j][0] = max(pd[i][j][0],pd[i][j+1][0] + 1);
            }
             
            res=max(res,pd[i][j][0]);
 
            for(int k=1;k<=K;k++) {              
                pd[i][j][k]=0;
                aux1=aux2=0;
                if(M[i][j] < M[i-1][j]) 
                    aux1 = pd[i-1][j][k] + 1;                 
                if(ehprimo(M[i-1][j]))
                    aux1 = max(aux1, pd[i-1][j][k-1] + 1);                 

                if(M[i][j] < M[i][j+1]) 
                    aux2 = pd[i][j+1][k] + 1;                 
                if(ehprimo(M[i][j+1]))
                    aux2 = max(aux2, pd[i][j+1][k-1] + 1);                 

                pd[i][j][k] = max(pd[i][j][k],max(aux1,aux2));
                res=max(res,pd[i][j][k]);
            }
            // for(int k=0;k<=K;k++) {  
            //     printf("pd[%d][%d][%d]=%d\n", i,j,k, pd[i][j][k]);
            // }
        }
    }
 
}
 
 
int main() {
    int i, j;
    char P;
    crivo(MAX);
 
    while(scanf("%d %d %d", &L, &C, &K) && L ) {
        scanf(" %c", &P);
 
        for(j=0;j<=C+1;j++) M[0][j]=M[L+1][j]=0;
        for(j=0;j<=L+1;j++) M[j][0]=M[j][C+1]=0;
 
        for(i=1;i<=L;i++) {
            for(j=1;j<=C;j++) {
                scanf("%d", &M[i][j]);
            }
        }
 
        res = 0;
        if(P=='N'){
            pd1();      
        } else {
            pd2();  
        }
         
        printf("%d\n",res+1);
 
    }
 
    return 0;
}