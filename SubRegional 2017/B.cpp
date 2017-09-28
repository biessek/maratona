#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int mask;
int n, t, y;
int a0, x;
int used[MAX];
int i, f;

void solve() {
    i=0;
    f=-1;
    int s = 0;
    int p;
    int a = a0;
    int pulso = 0;
    fill(used,used+MAX, -1);
    while(pulso < 3000000) {
        s = (s + a) % x;
        if(s == 0 && pulso+1 >= y) {
            i = 0;
            f = pulso; 
            break;
        }
        if(used[s] == -1) {
            used[s] = pulso;    
        } else if(pulso-used[s] >= y){
            f = pulso;
            i = used[s]+1;
            break;
        }
        
        // if(a == a0 && pulso > 0) break;
    //pulso
        p = a&mask;   
        a >>=1;
        
        int xx = p%2;
        for (int k = 1; k < n; k++) if(mask & (1<<k)) xx ^= ((p & (1<<k))>0);
        
        if(xx == 1) a |= (1 << (n-1));
        pulso++;
    }
}

int main() {
    scanf("%d %d %d %d %d", &n, &t, &a0, &x, &y);
    for (int i = 0, ti; i < t; i++) {
        scanf("%d", &ti);
        mask |= (1<<ti);
    }
    solve();
    if(f==-1) puts("impossivel");
    else printf("%d %d\n",i, f);
    return 0;	
}