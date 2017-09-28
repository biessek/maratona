#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<cmath>
using namespace std;
typedef vector<int> vi;
vector<long long> est(1000100);
vi foi(1000100);
int main() {
	long long t=0;
	int N, i;
	scanf("%d", &N);
	for(i=1;i<=N;i++) {
		scanf("%lli", &est[i]);
		foi[i]=true;
		t+= est[i];
	}
	int qt;
	long long res=0;	
	qt=0;
	for(i=1;i<=N && i>=1;) {
		if((est[i] % 2) ==0) {
			if(est[i]>0) {
				est[i]--;
				res++; 
			}
			if(foi[i]) {
				qt++;
				foi[i]=false;
			}
			
			i--;
		} else {
			if(est[i]>0) {
				est[i]--;
				res++; 
			}
			if(foi[i]) {
				qt++;
				foi[i]=false;
			}
			
			i++;
		}
	}
	printf("%d %lli\n",qt, t-res);

	return 0;
}