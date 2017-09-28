#include <cstdio>
#include <cstring>

int main() {
    int n, i, p;
    int a;
    bool ok;
    scanf("%d\n", &n);
    scanf("%d", &a);        
    p=0; ok=true;
    while((a+p)%n!=0)p++;
    for(i=1;i<n;i++) {
        scanf("%d", &a);                
        if(i&1){
            if(a-p>0) { ok&=((a-p) == i); continue;}
            else {ok&=((n+a-p) == i); continue;}
        } else {
            ok&=((a+p)%n) == i;
        }
        
    }
    if(ok) puts("Yes");
    else puts("No");
    return 0;
}
