#include <cstdio>
#include <algorithm>
using namespace std;

long long bt[500001];
int n;
void up(int i, int r, int x) {
    for(;i<=r; i += (i & (-i))) bt[i]+=x;
}

long long sum(int i) {
    long long res=0;
    
    for(;i>1; i -= (i & (-i))) res+=bt[i];
}

// if in tree exists more than one index with a same
// cumulative frequency, this procedure will return 
// some of them (we do not know which one)

// bitMask - initialy, it is the greatest bit of MaxVal
// bitMask store interval which should be searched
int find(int cumFre){
    int idx = 0; // this var is result of function
    
    while ((bitMask != 0) && (idx < MaxVal)){ // nobody likes overflow :)
        int tIdx = idx + bitMask; // we make midpoint of interval
        if (cumFre == tree[tIdx]) // if it is equal, we just return idx
            return tIdx;
        else if (cumFre > tree[tIdx]){ 
                // if tree frequency "can fit" into cumFre,
                // then include it
            idx = tIdx; // update index 
            cumFre -= tree[tIdx]; // set frequency for next loop 
        }
        bitMask >>= 1; // half current interval
    }
    if (cumFre != 0) // maybe given cumulative frequency doesn't exist
        return -1;
    else
        return idx;
}

int findG(int f){
    int idx = 0;
    int bitMask = f;
    
    while ((bitMask != 0) && (idx < MaxVal)){
        int tIdx = idx + bitMask;
        if (f >= bt[tIdx]){ 
                // if current cumulative frequency is equal to cumFre, 
                // we are still looking for higher index (if exists)
            idx = tIdx;
            cumFre -= bt[tIdx];
        }
        bitMask >>= 1;
    }
    if (f != 0)
        return -1;
    else
        return idx;
}

int main() {
    int n, q, i, x, l, r, op, y;
    scanf("%d %d", &n, &q);

    for(i=0;i<=n;i++) {
        bt[i]=0;
    }
    for(i=0;i<n;i++) {
        scanf("%d", &x);        
        up(i,n,x);
    }
    while(q--) {
        scanf("%d", &op);
        if(op==1) {
            scanf("%d %d %d", &l, &r, &x);
            up(l,r,x);
        }
        else {
            scanf("%d", &y);
            if(
        }
    }
    return 0;
}
