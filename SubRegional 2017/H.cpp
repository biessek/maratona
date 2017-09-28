#include <bits/stdc++.h>
using namespace std;
const unsigned MAX = 101;
typedef pair<int,int> ii;

int X[MAX], Y[MAX];
bitset<MAX> good[MAX];
const double EPS = 1e-9;
int dp[MAX];

double cross(int xa, int ya, int xb, int yb) { return xa * yb - ya * xb; }

bool isgood(int xa, int ya, int xb, int yb, int xc, int yc) {
    double cr = cross(xb-xa, yb-ya, xc-xa, yc-ya);

    return fabs(cr) > EPS && cr < 0.;
}

int main() {
    int n, xa, xb;
    scanf("%d %d %d", &n, &xa, &xb);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }
    
    queue<ii> q;
    for (int i = 0; i < n; i++) {
        bool umbom=false;
        for (int j = 0; j < n; j++) {
            if(i==j) continue;
            good[i][j] = isgood(xa, 0, X[i], Y[i], X[j], Y[j]) && isgood(X[i], Y[i], xb, 0, X[j], Y[j]);
            umbom |= good[i][j];
        }
        if(!umbom) q.push(ii(i, 1));
    }
    
    int ans = -1;
    fill(dp,dp+n, -1);
    while(!q.empty()) {
        int u  = q.front().first; 
        int qt = q.front().second;
        ans = max(ans, qt);
        q.pop();
        if(qt < dp[u]) continue;  
        for (int i = 0; i < n; i++) {
            if(i!=u&&good[i][u] && dp[i] < qt+1) {
                dp[i] = qt+1;
                q.push(ii(i, qt+1));
            }
        }       
    }
    printf("%d\n", ans);
    
    return 0;	
}