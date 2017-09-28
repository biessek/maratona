#include <bits/stdc++.h>
using namespace std;
typedef pair<int,unsigned> ii;
const int MAX = 10002;
unsigned c[MAX];
unsigned d;
unsigned L;
unsigned dist;
vector<ii> g[MAX];
int n, a, b, u;
unsigned k;
void dfs(int v, int p = 0) {
    int t = g[v].size();
    for (int i = 0; i < t; i++) {
        u = g[v][i].first;
        dist = g[v][i].second;
        if(u!=p) {
            d+=dist; /// ida
            dfs(u, v);
            d+=dist;
            c[v]+=c[u];
            
            if(c[u] > L) {
                d+= 2 * dist * ceil((c[u]-L) / double(L)); /// volta
            }
        }
    }
}
int main() {
    scanf("%d %u", &n, &L);
    for (int i = 1; i <= n; i++) {
        scanf("%u", &c[i]);    
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d %u", &a, &b, &k);    
        g[a].push_back(ii(b,k));
        g[b].push_back(ii(a,k));
    }
    d=0;
    dfs(1);
    printf("%u\n", d);
    return 0;	
}