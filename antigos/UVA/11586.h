#include <cstdio>
#include <cstring>

char t[50][3];
char l[10000];
int main() {
	int t;
	char *tok;
	scanf("%d\n", &t);
	while(t--) {
		scanf("%[^\n]\n", l);
		int q=0;
		tok=strtok(l,' ');
		while(tok!=NULL) {
			strcpy(t[q++],tok);
			tok=strtok(NULL,' ');			
		}
		printf("%d\n",q);
	}
	return 0;
}