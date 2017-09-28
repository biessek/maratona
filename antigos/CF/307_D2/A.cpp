#include <cstdio>
#include <algorithm>
using namespace std;

struct st  {
    int p;
    int rat;
} s[2000];

int pos[2001];

bool comp(const st &a,const st &b) {
    return a.rat == b.rat? a.p < b.p : a.rat > b.rat;
}
bool comp2(const st &a,const st &b) {
    return a.p < b.p;
}

int main() {
    int N, rating;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &rating);
        s[i].p = i;
        s[i].rat = rating;        
    }

    sort(s,s+N,comp);
    
    for(int i=0;i<=2000;i++) {
        pos[i]=300000;
    }
    
    for(int i=0;i<N;i++) {
        pos[s[i].rat] = min(pos[s[i].rat],i+1);
    }
    
    sort(s,s+N,comp2);
    printf("%d", pos[s[0].rat]);            
    for(int i=1;i<N;i++) {
        printf(" %d",pos[s[i].rat]);            
    }
    puts("");
    
    return 0;
}
