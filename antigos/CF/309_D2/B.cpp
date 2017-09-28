#include <cstdio>
#include <cstring>

int main() {
    char l[102][102], mr;
    int t, i, j, r[100];
    scanf("%d\n", &t);
    for(i=0;i<t;i++) r[i]=0;
    mr=0;
    for(i=0;i<t;i++) {
        scanf("%s\n", l[i]);
        for(j=i-1;j>=0;j--) {
            if(strcmp(l[j],l[i])==0) {
                r[i]++;
                if(r[i]>r[mr]) mr=i;
            }
        }
    }    
    printf("%d\n",r[mr]+1);
    return 0;
}
