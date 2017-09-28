#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN (int)1010
int  st[MAXN<<2][MAXN<<2];

int gcd(int a, int b) {
	return b? gcd(b,a%b) : a;
}

void change(int p1,int p2, int lx, int rx, int ly, int ry, int x, int y, int d) {
	if(lx > x || rx < x) return;
	printf("%d %d\n", p1,p2);
	int md;
	if(lx==rx) {
		if(ly > y || ry < y) return;
		if(ly==ry) {
			st[p1][p2]=d;
			return;
		}

		md = (ry+ly) >> 1;
		change(p1, p2<<1, lx, rx, ly, md, x, y, d);
		change(p1, p2<<1|1, lx, rx, md+1, ry, x, y, d);
		st[p1][p2] = gcd(st[p1][p2<<1],st[p1][p2<<1|0]);
	}
	md = (rx+lx) >> 1;

	change(p1<<1, p2, lx, md, ly, ry, x, y, d);
	change(p1<<1|1, p2, md+1, rx, ly, ry, x, y, d);
	st[p1][p2] = gcd(st[p1<<1][p2],st[p1<<1|1][p2]);
}

int query(int p1,int p2, int lx, int rx, int ly, int ry, int x1, int x2, int y1, int y2) {
	if(lx > x2 || rx < x1) return -1;	
	
	int md, q1, q2;
	if(lx>= x1 && rx <=x2) {
		if(ly > y2 || ry < y1) return -1;	
		if(ly>= y1 && ry <=y2) {			
			return st[p1][p2];
		}

		md = (ry+ly) >> 1;
		q1 = query(p1, p2<<1,   lx, rx, ly,   md, x1,x2,y1,y2);
		q2 = query(p1, p2<<1|1, lx, rx, md+1, ry, x1, x2, y1, y2);		
		if(q1 == -1) return q2;
		if(q2 == -1) return q1;

		return gcd(q1,q2);
	}

	md = (rx+lx) >> 1;
	q1 = query(p1<<1,   p2, lx,   md, ly, ry, x1, x2, y1, y2);
	q2 = query(p1<<1|1, p2, md+1, rx, ly, ry, x1, x2, y1, y2);		
	if(q1 == -1) return q2;
	if(q2 == -1) return q1;

	return gcd(q1,q2);
}

int main() {
	int C, i, d, x, y;
	char op;	
	while(scanf("%d",&C) != EOF) {
		memset(st,0,sizeof(st));
		for(i=0;i<C;i++) {
			scanf(" %c%*s %d %d %d", &op, &x, &y, &d);
			x+=500; y+=500;
			if(op == 'M') {								
				printf("h %d %d %d %d\n", x,y,d,d);				
				change(1, 1, 0, MAXN-1, 0, MAXN-1, x, y, d);
			} else {
				printf("%d\n", query(1, 1, 0, MAXN-1, 0, MAXN-1, 
									max(0,x-d),
									min(x+d,MAXN-1),
									max(0,y-d),
									min(y+d,MAXN-1)
								));
			}
		}
		puts("");
	}
	
	return 0;
}