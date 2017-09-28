#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
using namespace std;
typedef vector<int> vi;

int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.2lf", (b*100.0)/a - 100);	
	printf("%%\n");
	return 0;
}