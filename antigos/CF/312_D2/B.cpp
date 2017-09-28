#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


struct in{
    int c, is, ie;
} ct[1000001];

vector<int> nmm;

int main() {
    int n, a, m = -1, i;
    for(i=0;i<=1000000;i++) ct[i].c=0;
    nmm.clear();
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &a);        
        if(ct[a].c==0) {
            ct[a].is = i;
            ct[a].ie = i;        
        } else {
            ct[a].ie = i;        
        }
        ct[a].c++;
        if(ct[a].c > m) {
            nmm.clear();
            m = ct[a].c;
            nmm.push_back(a);
        } else if(ct[a].c == m){
            nmm.push_back(a);
        }     
    }


    int t=nmm.size();
    for(i=1;i<t;i++) {
        if((ct[nmm[i]].ie-ct[nmm[i]].is+1) < (ct[nmm[0]].ie-ct[nmm[0]].is+1)) {
            swap(nmm[i],nmm[0]);
        }
    }
    printf("%d %d\n",ct[nmm[0]].is+1,ct[nmm[0]].ie+1);
  
    return 0;
}
