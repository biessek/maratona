#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
    const int MAXN = 10100;
    const int MAXC = 1100;
    const int ALF  = 26;
    const int FAIL = -1;
    const int MAXS = 1000100;
int T[MAXN];
 
        map<int,int>::iterator it;
 
class AhoCorasick {
    public:
        char K[MAXN][MAXC];
        int stt;
        map<int,int> g[MAXS];
        vector<int> gv[MAXS];
        int f[MAXS];
        int KS[MAXN];
        bool FP[MAXS];
        long long memo[MAXS];
        long long mm;
        AhoCorasick() {
        }   
 
        void add(int i) {
            int j;
            int s=0;
            int c;
            for(j=0;j<T[i];j++) {
                c = K[i][j] - 'a';
                if(g[s].find(c) == g[s].end()) break;
                s=g[s][c];
            }   
            while(j<T[i]) {
                c = K[i][j++] - 'a';                
                g[s][c] = stt;
                s = stt++;
            }
            KS[i]=s;
            FP[s]=true;
        }
 
        void completa() { // cria a fail e a output.
            int j, ns, state;

            queue<int> q;
            for(j=0;j<ALF;j++) {
                if(g[0].find(j) == g[0].end()) {                	
                	g[0][j] = 0;	
                } else {
                	f[g[0][j]] = 0; // profundidade 1 - falha vai pro 0
	                q.push(g[0][j]);    
	                memo[g[0][j]]=FP[g[0][j]];
           	 	}
            }
            while(!q.empty()) {
                int s = q.front(); q.pop();
  //              printf("%d\n", s);
                for(it=g[s].begin();it!=g[s].end();it++) {
                	j=(*it).first;
//	                printf("%c\n", j+'a');
                    ns = (*it).second;
//	                printf("%d %d\n", ns, f[s]);
                    q.push(ns);             
 
                     
                    state = f[s];
                    while(g[state].find(j)==g[state].end()) {                        
                        state = f[state];                        
                    }
                    
                    f[ns] = g[state][j];                    
                    memo[ns]=max(memo[s],memo[f[ns]]) + FP[ns];
                    mm=max(mm,memo[ns]);
                }               
            }           
        }
        void reset() {
            int j,i;
            mm=0;
            for(i=0;i<MAXS;i++) {
            	g[i].clear();
            	gv[i].clear();
                f[i]=FAIL;
                memo[i]=0;
                FP[i]=false;
            }
            stt = 1; //o 0 é a raiz.        
        }
};
 
int N;
AhoCorasick aho = AhoCorasick();
 
int main() {
    int i;
    while(scanf("%d", &N) && N) {
        aho.reset();
        for(i=0;i<N;i++) {
            scanf(" %s", aho.K[i]);         
            T[i]=strlen(aho.K[i]);
            aho.add(i);
 		} 
        aho.completa(); 
 
        printf("%lli\n",aho.mm);                
    }
    return 0;
}