#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int ca[10000];
int cb[10000];
map<int,bool> f;
int main() {
    int A, B, i, ctda, ctdb, ta, tb;
    while(scanf("%d %d", &A, &B) && A) {
		ctda=ctdb=ta=tb=0;	
		f.clear();
		for(i=0;i<A;i++) {
			scanf("%d", &ca[i]);
		}	
		ctda= A-ctda;
		for(i=0;i<B;i++) {
			scanf("%d", &cb[i]);			
			if(!f[cb[i]] && !binary_search(ca,ca+A,cb[i])) { ta++; f[cb[i]]=true;}			
		}	f.clear();
		for(i=0;i<A;i++) {
			if(!f[ca[i]] && !binary_search(cb,cb+B,ca[i])) {tb++;	f[ca[i]]=true;}		
		}		
		printf("%d\n", min(tb,ta));
		
		
	}
    
    return 0;
}
