#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll d1, d2, d3;
	scanf("%lli %lli %lli", &d1, &d2, &d3);
	printf("%lli\n", min(min(min(d1+d2+d3,d1*2+d2*2),d1*2+d3*2),d2*2+d3*2));
	return 0;
}