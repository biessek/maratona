#include<cstdio>


int main() {
	int l[4];
	for(int i=0;i<4;i++) {scanf("%d", &l[i]);}
			
	bool ok=false;		
	for(int i=0;i<4;i++) {
		for(int k=0;k<4;k++)
			for(int j=0;j<4;j++) {
				if(i!=k && i!=j && j != k) {
					if(l[i] < l[j]+l[k] && l[j] < l[i]+l[k] && l[k] < l[j]+l[i]) ok=true;
				}
			}
	}
	if(ok) puts("S");
	else   puts("N");
 	return 0;
}