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
	printf("%.2lf%%\n", (b/100.)*a);	
	return 0;
}