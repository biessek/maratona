#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{int a,b;} v;
int n;
int a[100005];
int c[100005];
int t[100005];
int ok[100005];
bool f[100005];
vector<int> vc;
queue<v> q;
v l, novo;
int qvs;
int main() {
    int max = -1, i;
    vc.clear();
    scanf("%d", &n);
    for(i=0;i<=100000;i++) { c[i]=t[i]=0; ok[i]=0; f[i]=false;}
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
        if(a[i]>max) max = a[i];
    }
    qvs=0;
    for(i=0;i<n;i++) {
        l.a=a[i]; l.b=0;       
        q.push(l);                   
        while(!q.empty()) {            
            l=q.front(); q.pop();    
            
            c[l.a]++;
            if(c[l.a]>=n && !f[l.a]) {
                vc.push_back(l.a); f[l.a]=true;
                qvs++;
            }
            
            ok[l.a]=i+1;
            
            t[l.a]+=l.b;   

            novo.b=l.b+1;
            if(l.a > 0) {
                novo.a = l.a >> 1;
                if(novo.a && ok[novo.a] <= i) {                    
                    q.push(novo);
                }
                novo.a = l.a << 1;
                if(novo.a && novo.a <= max && ok[novo.a]<=i) {
                    q.push(novo);
                }
            }            
        }
    }
    for(i=1;i<qvs;i++) {
        if(t[vc[i]] < t[vc[0]] ) swap(vc[0],vc[i]);
    }
    printf("%d\n",t[vc[0]]);
    return 0;
}
