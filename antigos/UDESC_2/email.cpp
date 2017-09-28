#include <cstdio>
#define NAO_ENV 0
#define ENVIADO 1
#define FINALIZADO 2

int E;
char nome[51][25];

int g[51];

int M[51][51];

int V[51];

int parent[51];

bool P[51];
 
bool loop[51];

bool pt;


void dfs(int u) {
    V[u] = ENVIADO;
    for(int i=0;i<g[u];i++) {
        if(V[M[u][i]] == NAO_ENV) {
            parent[M[u][i]] = u;
            dfs(M[u][i]);
        } else if(V[M[u][i]] == ENVIADO){
            loop[M[u][i]] = true; // tem loop partindo deste vertice
            pt=true;
            return;
        }
    }
    V[u] = FINALIZADO;
}

void dfs2(int u) {
    loop[u]=true;
    for(int i=0;i<g[u];i++) {
        if(!loop[M[u][i]]) dfs2(M[u][i]);
    }
}
int main() {
    int p, s,i,j, k;
    
    scanf("%d", &E);
    for(i=1;i<=E;i++) {
        pt=false;
        printf("E-Mail #%d:\n",i);

        scanf("%d %d\n", &p, &s);
        for(j=1;j<=p;j++) {    
            loop[j]=P[j]=false;
            V[j]= NAO_ENV;
            scanf("%s ", nome[j]);            
        }
        
        for(j=1;j<=p;j++) {    
            scanf("%d", &g[j]);
            for(k=0;k<g[j];k++) {                
                scanf("%d", &M[j][k]);
            }            
        }
        
        dfs(s);
         
      
        
        if(!pt)
            printf("E-Mail seguro!");
        else {
            for(j=1;j<=p;j++) {    
                if(loop[j]) dfs2(j);
            }
            pt=false;
            for(k=1;k<=p;k++) {    
                if(loop[k]) {
                    printf("%s ", nome[k]);
                }
            }
        }
        puts("");
        puts("");        
    }

    return 0;
}
