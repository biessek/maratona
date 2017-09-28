#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> ii;

struct cc {
	int n, p;
} L[100];
cc a, b;
int main() {
	int i, p,ia,ib,nn,np;	
	int N;	
	while( scanf("%d", &N) != EOF) {
		for(i=0;i<N;i++) { 
			scanf("%d", &L[i].n); L[i].p=1;
		}		

		while(true) {
			ia=0; 
			for(i=1;i<N;i++) 
				if(L[i].n > L[ia].n) ia=i;
				else if(L[i].n == L[ia].n && L[i].p < L[ia].p)  ia=i;
			ib=-1;
			for(i=0;i<N;i++) 
				if(i!=ia) {
					if(L[i].n > L[ib].n) ib=i;
					else if(L[i].n == L[ib].n && L[i].p < L[ib].p)  ib=i;
				}

			if(ib==-1 || L[ib].n==-1) break;
			if(L[ia])
			np=L[ia].p+L[ib].p;
			nn=min(L[ia].n,L[ib].n)-1;			
			L[ia].n=nn;
			L[ia].p=np;
			L[ib].n=L[ib].p=-1;
		}
		printf("%d\n", L[ia].p);
	}
	return 0;
}