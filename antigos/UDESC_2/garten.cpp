#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
int it[501];
int mapa[501][251];

int knap(int i, int c) {
//    printf("%d=%d\n",i,c);
    if(c<=0 || i<=0) return 0;

    if(mapa[i][c]!=-1) {
//        printf("h|mapa[%d][%d]= %d\n",i,c,mapa[i][c]);
        return mapa[i][c];
    }

    mapa[i][c] = max(knap(i-1,c),knap(i-1,i/2-1)+it[i]);
//    printf("mapa[%d][%d]= %d\n",i,c,mapa[i][c]);
    return mapa[i][c];

}

int main() {
    int n, i, j ,k, resp;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        scanf("%d", &k);
        for(j=1;j<=k;j++) {
            scanf("%d", &it[j]);            
        }

        for(j=1;j<=500;j++) {
            for(int q=1;q<=250;q++) {
                mapa[j][q]=-1;
            }
        }
        resp= knap(1,1);
        for(j=2;j<=k;j++) {           
            resp = max(resp, knap(j, j/2));
//            printf("%d: %d\n",j, mapa[j][j/2]);
        }        
        printf("Maratona #%d: %d\n",i, resp);
                     
    }

    return 0;
}
