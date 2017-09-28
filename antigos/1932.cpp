#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
typedef std::vector<int> vi;
#define MAXN 200100
#define MAXP 1100

vi P(MAXN);
vector<vi> V(MAXN,vi(3));
int N, C;
int main() {
	int i;
	scanf("%d %d", &N, &C);
	for(i=0;i<N;i++) {
		scanf("%d", &P[i]);		
		V[i][0]=V[i][1]=V[i][1]=0;
	}
	V[0][0]=0; //sem fz nada
    V[0][1]=-P[0]; //comprando
    V[0][2]=0;////vendendo
    
    for(i=1;i<N;i++) {
		V[i][0]=max(max(V[i-1][0],V[i-1][1]),V[i-1][2]); //sem fz nada
		
		//comprando
	    V[i][1]=max(V[i-1][0] - P[i], V[i-1][1]); //ou
	    V[i][1]=max(V[i][1], V[i-1][2] - P[i]);

		//comprando
	    V[i][1]=max(V[i-1][0] - P[i], V[i-1][1]); //ou
	    V[i][1]=max(V[i][1], V[i-1][2] - P[i]);

		//vendendo
	    V[i][2]=max(V[i-1][1] - C + P[i], V[i-1][2]);

    }
	printf("%d\n",max(max(V[N-1][0],V[N-1][1]),V[N-1][2]));
}