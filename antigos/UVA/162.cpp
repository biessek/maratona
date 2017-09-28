#include <cstdio>
#include <queue>
using namespace std;
typedef struct {char S,R;} card;

int main() {
    card l;
    deque<card> desk;
    deque<card> p[2];
    int i, pv, qtc, lf;
    while(scanf(" %c", &l.S) && l.S != '#') {
        p[0].clear();
        p[1].clear();
        desk.clear();

        scanf("%c", &l.R);
        p[1].push_back(l);
        pv=0;
        for(i=1;i<52;i++) {
            scanf(" %c%c", &l.S, &l.R);
            p[pv].push_back(l);
            pv=!pv;
        } 
        qtc=1; lf = -1;
        while(!p[pv].empty()) {
            while(qtc && !p[pv].empty()) {
                l=p[pv].back();
                desk.push_front(l); p[pv].pop_back();
                qtc--;
                if(l.R=='K'|| l.R == 'Q' || l.R == 'J' || l.R=='A') {
                    qtc= l.R=='A'? 4 : l.R=='K'? 3 : l.R=='Q'? 2 : 1;                    
                    lf = pv;
                    break;
                } 
            }
            if(qtc && p[pv].empty() && lf != pv) { // lose
                break;
            }
            if(!qtc && lf!=-1) {
                while(!desk.empty()) {
                    p[lf].push_front(desk.back()); desk.pop_back();
                }
                lf=-1; 
            } 
            if(lf==-1)qtc=1;
            pv=!pv;
        }        
        pv=!pv;
        printf("%d%3d\n", pv+1,p[pv].size());
    }
    
    return 0;
}
