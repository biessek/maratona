#include <cstdio>
#include <map>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define MAXN 201000
#define MAXC 1100

map<int,map<int,long long> >memo;
long long P[MAXN];
long long N, C;

long long maxn(int i, int v) {	
	if(i > N ) {
		return 0;
	}
	if(memo.find(i)!=memo.end() && memo[i].find(v) != memo[i].end()) return memo[i][v];
	
	long long r[3]= {0, 0, 0};
	if(v) {
		r[0]=maxn(i+1,0) + P[i] - v - C;
		r[1]=maxn(i+1,v);
	}
	r[2]=maxn(i+1,P[i]);
	memo[i][v] = max(r[0],r[1]);
	memo[i][v] = max(memo[i][v],r[2]);
	return memo[i][v];
}

int main() {
	int i, j;
	scanf("%lli%lli",&N,&C);
	
	for(i=1;i<=N;i++) 
		scanf("%lli", &P[i]);
	
	memo.clear();
		
	printf("%lli\n", maxn(1,0));	
	return 0;
}