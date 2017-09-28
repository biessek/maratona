#include <cstdio>
#include <climits>
#include <list>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int m, l, i,t=1;
    list<char> alfa;
    list<char>::iterator it;
    char saida[10003], topo;
    while(scanf("%d", &m) && m) {
        alfa.clear();
        for(i=0;i<26;i++)
            alfa.push_back('A'+i);
            
        i=0;
        while(m--) {
            scanf("%d", &l);
            it = alfa.begin(); l--;
            topo = alfa.front();
            while(l--) {
                it++;
                topo = *it;
            }
            saida[i++]=topo;
            alfa.erase(find(alfa.begin(),alfa.end(),topo));
            alfa.push_front(topo);
        }
        saida[i++]='\0';
        printf("Instancia %d\n%s\n\n",t++,saida);
    }
    return 0;
}


