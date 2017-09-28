#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int L,i, lf, ld,md;
	char c;
	lf=-1;ld=-1;
	
	while(scanf("%d\n", &L)&&L) {
		md=L+1; lf=ld=-1;
		for(i=0;i<L;i++) {
			c=getchar();
			if(md==0) continue;
			if(c=='R') {
				lf=i;
			}else if(c=='D') {
				ld=i;
			} else if(c=='Z'){
				ld=i;
				lf=i;
			}
			if(ld!=-1&&lf!=-1)
				md=min(md,abs(ld-lf));
		
		}		
		printf("%d\n",md);
		
	}
	return 0;
}