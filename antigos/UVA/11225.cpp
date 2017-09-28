#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char card[100];

bool trump() {
    return (strcmp(card,"fool")==0) || 
           (strcmp(card,"twenty-one of trumps")==0) ||
           (strcmp(card,"one of trumps")==0);
}

int val() {
    if(trump()) return 450;
    if(card[0]=='k' && card[1]=='i'  && card[2]=='n'  && card[3]=='g') return 450;
    if(card[0]=='q' && card[1]=='u'  && card[2]=='e'  && card[3]=='e') return 350;
    if(card[0]=='k' && card[1]=='n'  && card[2]=='i'  && card[3]=='g') return 250;
    if(card[0]=='j' && card[1]=='a'  && card[2]=='c'  && card[3]=='k') return 150;
    return 50;
}

int main() {
    int t, i, trc, pt, m, r;
    scanf("%d", &t);
    for(i=1;i<=t;i++) {
        trc=pt=0;
        scanf("%d\n", &m);
        while(m--) {
            scanf("%[^\n]\n", card);
            if(trump()) trc++;
            pt+=val();
        }
        if(trc==0) r= 5600;
        else if(trc==1) r= 5100;
        else if(trc==2) r= 4100;
        else r= 3600; 

        if(i>1) puts("");
        printf("Hand #%d\n", i);
        if(pt < r) printf("Game lost by %d point(s).\n", (r-pt)/100);
        else printf("Game won by %d point(s).\n", (pt-r)/100);
               
    }


    return 0;
}
