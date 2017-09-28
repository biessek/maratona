/*

 estado(i, j)
 estado(TEMPO = T, n,n+1, n+2 .... m)
 estado(TEMPO = T, quantidade de treino iniciados em n).

 base cases:
 F(1, 1) = 0
 F(1, 2) = 1                        
 F(1, 3) = 1                        
 F(1, 4) = 1                        
 F(1, 5) = 1                        
 F(1, 6) = 0
 
 demais: Sendo F(i,j) a quantidade de programas de tempo T(i) que iniciam em dificuldade(j). Concaternar os programas baseando-se na regra de dificuldade(+1 -1)
 
 posso concatenar o j atual com os treinos de tempo i-1 iniciados em j-1 e j+1.
 
 F(2, 2) = F(1,3) + F(1,1) = 1      // 2,3  
 F(2, 3) = F(1,4) + F(1,2) = 2      // 3,2,| 3,4
 F(2, 4) = F(1,5) + F(1,3) = 2      // 4,3 | 4,5
 F(2, 5) = F(1,6) + F(1,4) = 1      // 5,4 
 
 F(3, 2) = F(2,3) + F(2,1) = 2      // 2,3,2 | 2,3,4
 F(3, 3) = F(2,4) + F(2,2) = 3      // 3,4,3 | 3,4,5 | 3,2,3
 F(3, 4) = F(2,5) + F(2,3) = 3      // 4,5,4 | 4,3,2 | 4,3,4
 F(3, 5) = F(2,6) + F(2,4) = 2      // 5,4,3 | 5,4,5 
 ...

 A soma dos programas iniciados em 2 + os iniciados em 3 + os iniciados em 4 + os iniciados em 5 é a resposta = 10.
 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;

const int MAXT = 51;
const int MAXN = 100002;
ll ans[MAXT][MAXN];

const ll P = 1000000007;

int main() {
    int t, n, m, i, j;
    scanf("%d %d %d", &t, &n, &m);

    // base
    for (int i = n; i <= m; i++) { ans[1][i] = 1; }
    for (int i = 1; i <= t; i++) { ans[i][n-1] = ans[i][m+1] =0; }
    
    for (int i = 2; i <= t; i++) {
        for (int j = n; j <= m; j++) { 
            ans[i][j] = (ans[i-1][j-1] + ans[i-1][j+1]) % P;
        }
    }
    ll r = 0;
    for (int j = n; j <= m; j++) r = (r + ans[t][j]) % P;

    printf("%llu\n",r);
    
    return 0;	
}