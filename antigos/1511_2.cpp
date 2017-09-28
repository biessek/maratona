#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
 
typedef int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;
 
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define EPS 1e-7
#define PI  3.1415926535897932384626433832795028841971693993
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
 
//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////
 
 #define getcx getchar_unlocked
 
 inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  } 
 
const int N = 1001;
 
ll tr[4*N*N];
int n,m;
 
ll join( ll a, ll b, ll c, ll d )
{
    return __gcd(__gcd(a,b),__gcd(c,d));
}
 
void update( int no, int lx, int rx, int ly, int ry, int i, int j, int val )
{
    if( rx < i || lx > i || ry < j || ly > j ) return;  
    if( lx==rx && ly==ry )
    {
        tr[no] = val;
        return;
    }
 
    int nxt = (no*4);
    int m1 = (lx+rx)>>1;
    int m2 = (ly+ry)>>1;
 
    update(nxt-2,lx,m1,     ly,m2,      i,j,val);
    update(nxt-1,lx,m1,     m2+1,ry,    i,j,val);
 
    update(nxt+0,m1+1,rx,   ly,m2,      i,j,val);
    update(nxt+1,m1+1,rx,   m2+1,ry,    i,j,val);
 
    tr[no] = join(tr[nxt-2],tr[nxt-1],tr[nxt+0],tr[nxt+1]);
}
 
void update( int x, int y, int val )
{
    update(1,0,1000,0,1000,x,y,val);
}
 
 
bool valido(int li,int ri,int lj, int rj,int i,int j,int d){
    if(i>=li && i<=ri && j>=lj && j<=rj)return true;
    if(i>=li && i<=ri)return (min(abs(j-rj),abs(j-lj))<=d);
    if(j>=lj && j<=rj)return (min(abs(i-ri),abs(i-li))<=d);
    return(min(min(abs(i-li) + abs(j-lj),abs(i-li) + abs(j-rj)),min(abs(i-ri) + abs(j-lj),abs(i-ri) + abs(j-rj)))<=d);
}
 
ll hd( int a, int b, int c, int d){ return abs(a-c)+abs(d-b); }
 
ll query( int no, int lx, int rx, int ly, int ry, int x, int y, int d )
{
    if(lx>rx || ly>ry) return 0;
    if( !valido(lx,rx,ly,ry,x,y,d) ) return 0; 
    if( hd(lx,ly,x,y)<=d && hd(lx,ry,x,y)<=d && hd(rx,ly,x,y)<=d && hd(rx,ry,x,y)<=d ) return tr[no];
 
    int nxt = (no*4);
    int m1 = (lx+rx)>>1;
    int m2 = (ly+ry)>>1;
 
    ll p1 = 0, p2 = 0, p3 = 0, p4 = 0;
 
    p1 = query(nxt-2,lx,m1,     ly,m2,      x,y,d);
    p2 = query(nxt-1,lx,m1,     m2+1,ry,    x,y,d);
 
    p3 = query(nxt+0,m1+1,rx,   ly,m2,      x,y,d);
    p4 = query(nxt+1,m1+1,rx,   m2+1,ry,    x,y,d);
 
    return join(p1,p2,p3,p4);
}
 
ll query( int x, int y, int d )
{
    return query(1,0,1000,0,1000,x,y,d);
}
 
int main()
{
    //ios::sync_with_stdio(0);
 
    int q;
    while( scanf("%d",&q) != EOF ) 
    {
        memset(tr,0,sizeof tr);
        char s[100];
        while(q--)
        {
            scanf(" %s",s);
            ll x,y,d;
            inp(x);inp(y);inp(d);
            x+=500;
            y+=500;
            if(strcmp(s,"SET") == 0)
                update(x,y,d);
            else
                printf("%d\n",query(x,y,d));
        }
    }
 
    return 0;
 
}