#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<bitset>
#include<cstring>
#include<set>
using namespace std;
typedef vector<int> vi;
#define MAXS 128100
 
int D, L, S;
vi g[MAXS];
int f[MAXS];
int term[MAXS];
char p[MAXS];
int t;
int states;
 
void add() {
    int i,c;
    int s=0;
    for(i=0;i<t;i++) {
        c = p[i] - 'a';
        if(g[s][c] == -1) break;
        s=g[s][c];
    }
    while(i<t) {
        c = p[i++] - 'a';
        g[s][c]=states++;
        s = g[s][c];
    }
    term[s] = true;
}
 
void bf() {
    int i, s, ns, sp;
    queue<int> q;
    f[0]=0;
    for(i=0;i<L;i++) {
    	if(g[0][i] == -1) {
    		g[0][i] = 0;   // terminar a go
    	}
    }
 
    for(i=0;i<L;i++) {
        if(g[0][i] == 0) continue;
        f[g[0][i]] = 0;
        q.push(g[0][i]);
    }
 
    while(!q.empty()) {
        s=q.front(); q.pop();
        for(i=0;i<L;i++) {
            if(g[s][i] == -1) continue;
            ns = g[s][i]; 
            q.push(ns);
 
 			
            sp = f[s];
            while(g[sp][i] == -1) sp = f[sp];
            f[ns] = g[sp][i];
            term[ns] |= term[f[ns]];
        }
    }   
}
vi memo[MAXS];
int getstt(int s, int c) {
    if(g[s][c]==-1){
        int sp=f[s];
        while(g[sp][c]==-1) sp=f[sp];
        return g[sp][c];
    }
    return g[s][c];
}
 
int cgrundy(int s, int j) {
    // printf("s %d.%d, memo %d\n",s,j, memo[s][j]);
    if(j == 0) return (memo[s][j] = 0); 
    if(memo[s][j]!=-1) return memo[s][j];
    if(term[s]) {
        return (memo[s][j] = 0);
    }
 
    set<int> sg;
    int ns;
    for(int i=0;i<L;i++) {
        ns = getstt(s,i);
        // printf("%d -> %d(%c)\n",s,ns,i+'a');
        sg.insert(cgrundy(ns,j-1));
    }
 
    int ret = 0;
    while(sg.find(ret) != sg.end()) { ret++;}
 
    // printf("CC %d %d = %d\n", s, j, ret);    
    return (memo[s][j]=ret);
}
int find() {
    int i,c, sp;
    int s=0;
    for(i=0;i<t;i++) {
        c = p[i] - 'a';
        if(g[s][c] == -1) {
            sp = f[s];
            while(g[sp][c] == -1) sp = f[sp];
            s=g[sp][c];
        } else {
            s=g[s][c];
        }

    }
    return s;
}
 
int main() {
    states=1;
    int i,j,S;
    scanf("%d %d", &D, &L);
 
    fill(g,g+MAXS, vector<int>(L,-1));
    fill(f,f+MAXS, -1);
    fill(term,term+MAXS, false);
    fill(memo,memo+MAXS, vi(55,-1));
 
    for(i=0;i<D;i++) {
        scanf(" %s", p);
        t = strlen(p);
        add();
    } 
    bf();
 

    scanf("%d", &S);
 
    int grundyant=-1;
    while(S--) {
        scanf(" %s %d", p, &j);
        t = strlen(p);
        // printf("%s %d\n",p,find());
        // printf("%s %d\n",p,find());       
        int grundy = cgrundy(find(),j);
        // printf("%d\n", grundy);      
        if(grundyant != -1) {
            grundyant ^= grundy;
        } else {
            grundyant = grundy;
        }
    }
    if(grundyant == 0) puts("Daenerys"); //perde
    else puts("Tyrion"); //ganha 
    return 0;
}