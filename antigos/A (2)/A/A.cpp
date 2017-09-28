#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef unsigned long long ll ;

	int f[10];
int mp() {
	for(int i=9;i>=0;i--) {
		if(f[i] < 2) return i;
	}
	return 0;
}
ll cor(int p, ll u) {
	char str[30];
	ll r = u - (p==1? 1 : ll(pow(10, p-1)));
	sprintf(str,"%llu", r);
	int t = strlen(str);
	for(int i=t-p+1;i<t;i++) {
		f[str[i]-'0']--;
	}
	for(int j=t-p+1;j<t;j++) {
		str[j]=mp()+'0';
		f[str[j]-'0']++;
	}
	sscanf(str,"%llu", &r);
	return r;
}

int main() {
	ll U, n;
	int dig;
	scanf("%llu", &U);

	while(true) {
		int last=-1;
		n = U;
		memset(f,0,sizeof(f));
		while(n>=10) {
			dig = n%10;
			n/=10;
			f[dig]++;
		} 
		dig=n;
		f[n]++;
		n = U;
		int c=0;
		while(n>=10) {
			c++;
			dig = n%10;
			n/=10;
			if(f[dig]>2) {
				last=c; break;
			}
		}
		if(last==-1) {
			dig=n; 
			c++;
			if(f[dig]>2) {
				last=c; 
			}
		}

		if(last!=-1) {
			U = cor(last, U);
		} else break;
	}

	printf("%llu\n", U);

	return 0;
}