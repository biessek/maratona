#include <cstdio>

bool lock(int k, int m) {
    return (k == 0 && m == 9) ||
           (k == 7 && m == 14) || 
           (k == 56 && m == 49) ||
           (k == 63 && m == 54);                      
}
bool leg(int q, int m, int k) {
    int c  = k%8;
    int r  = k/8;

    int cm = m%8;
    int rm = m/8;

    int ca = q%8;
    int ra = q/8;

    if(q==m) return false;
    if(rm!=ra && cm!=ca) return false;
    
    if(ca==c && ca==cm) 
        return ra > r? rm > r : rm < r;
    
    if(ra==r && ra==rm) 
        return ca > c? cm > c : cm < c;

    return true;
        
}

bool all(int k, int m, int q) {
    int c  = k%8;
    int r  = k/8;

    int cm = m%8;
    int rm = m/8;

    int ca = q%8;
    int ra = q/8;

    if(m==k) return false;

    if(cm == c+1||cm == c-1)  
        return r != rm;
    if(rm == r+1||rm == r-1)  
        return c != cm;
    return true;
}

int main() {
    int q,k, m;
    while(scanf("%d %d %d", &k, &q, &m) != EOF) {
        if(k==q)           puts("Illegal state"); 
        else if(!leg(q,m, k)) puts("Illegal move");
        else if(!all(k,m,q)) puts("Move not allowed");
        else if(lock(k,m)) puts("Stop");
        else puts("Continue");
    }

    return 0;
}
