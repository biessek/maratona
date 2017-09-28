#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> ii;
char t[110][1100];
int len[110];
int c[110][26];
int main() {
	int i,j, cd;	
	int N;	
	scanf("%d", &N);
	for(i=0;i<N;i++) {
		scanf(" %s", t[i]);
		len[i] = strlen(t[i]);
	}

	int s=0,sp;
	int k,si,sj;

	for(i=0;i<26;i++) {
		for(j=0;j<26;j++) {
			if(i==j) continue;
			sp=0;
			for(k=0;k<N;k++) { 
				int l;
				for(l=0;l<len[k];l++) if(t[k][l]!=i+'a'&&t[k][l]!=j+'a') break;
				if(l==len[k]) sp+=len[k];	
			}	
			if(sp>s) {
				si=i; sj=j;
				s=sp;
			}
		}
	}
	printf("%d\n",s);


	return 0;
}