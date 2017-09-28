#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
int mh[1012]; 
int main(){
	int n, h, i, vti, p, t;
	while(scanf("%d %d",&n,&h)!=EOF){
		vti=0;
		t=0;
		fill(mh,mh+1012,0);
		for(i=0;i<n;i++){
			scanf("%d %d",&p, &h);
			mh[h]=max(mh[h],p);
			t+=p;
		}
		vti=0;
		for(i=0;i<1012;i++){
			vti+=mh[i];
		}
		printf("%d\n",t-vti);
	} 
}
