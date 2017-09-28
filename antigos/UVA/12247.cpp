#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int p[3]; int pp[2]; int cc[5];
int main() {
    int A, B, C,D,E, d, c, w;
    while(scanf("%d %d %d %d %d", &p[0],&p[1],&p[2],&pp[0],&pp[1]) && p[0]) {
		d=0;
		sort(p,p+3);	
		sort(pp,pp+2);	
		cc[0]=p[0];
		cc[1]=p[1];
		cc[2]=p[2];
		cc[3]=pp[0];
		cc[4]=pp[1];
		c=1; w=0;
		for(d=0;d<3;d++) 
			for(c=1;c>=0;c--) {
				if(p[d]>pp[c]) {
					pp[c]=2000;
					p[d]=0;
					w++;
				}
			}
		
		if(w==2) puts("-1");
		else if(w){
			for(d=2;d>=0;d--) if(p[d]) {c=p[d]; break;}
			c++;
			while(c<53&&(c==cc[0]||c==cc[1]||c==cc[2]||c==cc[3]||c==cc[4])) c++;
			if(c<53) printf("%d\n",c);
			else puts("-1");
		} else {
			c=1;
			while(c<53&&(c==cc[0]||c==cc[1]||c==cc[2]||c==cc[3]||c==cc[4])) c++;
			if(c<53) printf("%d\n",c);
			else puts("-1");			
		}
	}
    
    return 0;
}
