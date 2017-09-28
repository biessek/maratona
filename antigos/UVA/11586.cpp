#include <cstdio>
#include <cstring>

int main() {
	int T, i, qm,qf, pecas;
	char l;
	scanf("%d\n", &T);
	while(T--) {
		qm=qf=pecas=0;
		while((l=getchar())!= EOF) {
			if(l=='\n') break;
			qm+=l=='M';
			qf+=l=='F';		
			pecas++;
		} 
		if(pecas > 2&&qm==qf) puts("LOOP");
		else puts("NO LOOP");
	}
	return 0;
}