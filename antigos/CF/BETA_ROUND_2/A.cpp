#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <map>
using namespace std;

map<string, int> mapa;

pair<int,int> placar[1000][1000];
int rd[1000];

char nomes[1000][35];
int main() {
    int N, i, pt, idx=0, jog, j, vezes, imaior;
    string nome;
    char ler[35];
    scanf("%d\n", &N);

    memset(rd, 0, sizeof(rd));

    for(i=0;i<N;i++) {
        scanf("%s %d\n", ler, &pt);
        nome = string(ler);
        if(mapa.find(nome) == mapa.end()) {
            mapa[nome]=idx++;
            strcpy(nomes[idx-1], ler);
            placar[mapa[nome]][0].first = pt;        
        } else {
            jog=mapa[nome];
            placar[jog][rd[jog]].first = placar[jog][rd[jog]-1].first + pt;        
        }
        jog=mapa[nome];

        placar[jog][rd[jog]].second = i;        

        rd[jog]++;     
    }

    int maior=-2000000, rmaior;
    for(i=0;i<idx;i++) {   
        if(placar[i][rd[i]-1].first > maior) {
            maior  = placar[i][rd[i]-1].first;
            rmaior = placar[i][rd[i]-1].second;
            imaior = i;
			
        }   
	}
		for(i=0;i<idx;i++) {   
			if(placar[i][rd[i]-1].first == maior)
				for(j=0;j<rd[i];j++) {			
					if(placar[i][j].first >= maior && placar[i][j].second < rmaior) {
						rmaior = placar[i][j].second;
						imaior = i;	
					}	
				}        
		}
    printf("%s\n",nomes[imaior]);
    return 0;
}
