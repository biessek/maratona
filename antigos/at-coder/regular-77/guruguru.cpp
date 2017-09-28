/*
4 6
1 5 1 4
*/

#include <bits/stdc++.h>
#define N 200006
using namespace std;
int n,m,x,y,t,a[N],s[N];long long sum,v[N];
inline int read()
{
	int x=0,c=getchar(),f=1LL;while(c<'0'||c>'9')f=(c=='-'?-f:f),c=getchar();
	while(c>='0'&&c<='9')x=(x<<1LL)+(x<<3)+c-48,c=getchar();return f>0?x:-x;
}
void print(long long x)
{
	if(x>9)print(x/10);putchar(x%10+48);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++){
		if(a[i-1]<a[i]) {
			sum+=a[i]-a[i-1];
			if(a[i-1]+1<a[i]) {
        s[a[i-1]+2]++;
        printf("i=%d\n", i);
        printf("s[%d]++ = %d\n", a[i-1]+2, s[a[i-1]+2]);
        s[a[i]+1]--;
        printf("s[%d]-- = %d\n", a[i]+1, s[a[i]+1]);
        v[a[i]+1]-=a[i]-a[i-1]-1;
        printf("v[%d]-=%d-%d-1(%d) = %d\n", a[i]+1, a[i], a[i-1],a[i]-a[i-1]-1, v[a[i]+1]);
      }
		} else {
			sum+=m-a[i-1]+a[i];
      printf("ii=%d\n", i);
			if(a[i-1]+1<m) {
        s[a[i-1]+2]++;
        printf("s[%d]++ = %d\n", a[i-1]+2, s[a[i-1]+2]);
        s[m+1]--;
        printf("s[%d]-- = %d\n", m+1, s[m+1]);
        s[1]++;
        printf("s[%d]++ = %d\n", 1, s[1]);
        s[a[i]+1]--;
        printf("s[%d]-- = %d\n", a[i]+1, s[a[i]+1]);
        v[0]+=m-a[i-1]-1;
        printf("v[%d]+=%d = %d\n", 0, m-a[i-1]-1, v[0]);
        v[a[i]+1]-=m-a[i-1]+a[i]-1;
        printf("v[%d]+=%d = %d\n", a[i]+1, m-a[i-1]+a[i]-1, v[a[i]+1]);
      }
      if(a[i-1]+1==m) {
        s[1]++;
        printf("s[%d]++ = %d\n", 1, s[1]);
        s[a[i]+1]--;
        printf("s[%d]-- = %d\n", a[i]+1, s[a[i]+1]);
        v[a[i]+1]-=m-a[i-1]+a[i]-1;
        printf("v[%d]+=%d = %d\n", a[i]+1, m-a[i-1]+a[i]-1, v[a[i]+1]);
      }
			if(a[i-1]==m&&1<a[i]) {
        s[2]++;
        printf("s[%d]++ = %d\n", 2, s[2]);
        s[a[i]+1]--;
        printf("s[%d]-- = %d\n", a[i]+1, s[a[i]+1]);
        v[a[i]+1]-=m-a[i-1]+a[i]-1;
        printf("v[%d]+=%d = %d\n", a[i]+1, m-a[i-1]+a[i]-1, v[a[i]+1]);
      }
		}
	}
  printf("sum=%lli\n", sum);
	long long ans=0;
	for(int i=1;i<=m;i++){
    printf("[%d]\n", i);
    printf("s[%d]=%d\n", i, s[i]);
		s[i]+=s[i-1];
    printf("s[%d]=%d\n", i, s[i]);
    printf("v[%d]=%d\n", i, v[i]);
    v[i]+=v[i-1]+s[i];
    printf("v[%d]=%d\n", i, v[i-1]+s[i]);
    if(v[i]>ans)ans=v[i];
	}
	printf("%lld\n",sum-ans);
}
