#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef map<int, int> sii;


vi spessoas;
sii G[100001];
sii::iterator it;
const int  INF = 1e9;
vector<bool> P;

int main() {
    int N, M, C, K, i, A, B, D;
    
    scanf("%d%d%d%d",&N, &M, &C, &K);
    spessoas.assign(C,0);
    P.assign(N+1,false);
    for(i=0;i<C;i++) {
        scanf("%d", &spessoas[i]);
        P[spessoas[i]]=1;
    }
    while(M--) {
        scanf("%d %d %d", &A, &B, &D);

        if(P[A]) {
            if(G[B].find(A) != G[B].end())
                G[B][A] = min(G[B][A],D<=K?0:D-K);
            else
                G[B][A] = D<=K?0:D-K;            
        } else {
            if(G[B].find(A) != G[B].end())
                G[B][A] = min(G[B][A],D);
            else
                G[B][A] = D;            
        }
    }
    int s = N;
      vi dist(N+1, INF); dist[s] = 0;                    // INF = 1B to avoid overflow
      
      priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
                                 // ^to sort the pairs by increasing distance from s
      while (!pq.empty()) {                                             // main loop
        ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;   // this check is important, see the explanation
        for (it = G[u].begin(); it != G[u].end(); it++) {
          ii v;                       // all outgoing edges from u
          v.first = (*it).first;
          v.second = (*it).second;
          if (dist[u] + v.second < dist[v.first]) {
            dist[v.first] = dist[u] + v.second;                 // relax operation
            pq.push(ii(dist[v.first], v.first));
      } } }  // note: this variant can cause duplicate items in the priority queue

    printf("%d\n",dist[1]);
    
    return 0;
}

