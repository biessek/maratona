#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<cmath>
using namespace std;
typedef vector<int> vi;
const double EPS=1e-9;

int main() {
	int c, av, bv, t, d;
	scanf("%d%d%d%d%d", &c, &av, &bv, &t, &d);
	c*=100; d*=100;
	int ap,bp; ap=bp=c-d;
	int tt=0;
	int r;
	t=t*60;
	while(tt < t-1) {
		ap = (ap + av) % c; 
		bp = (bp + bv) % c;  
		tt++;
	}	

	while(true) {
		if((ap + av) >= c) {
			r=1;
			break;
		} else if((bp + bv) >=c) {
			r=2; 
			break;
		}
		ap = (ap + av) % c; 
		bp = (bp + bv) % c;  
		tt++;
	}
	printf("%s\n", r==1? "Ana" : "Bia");
	return 0;
}