#include <cstdio>
char comm[100003];
int bt[100];

int main() {
    int T, i, j, p;
    char l;
    scanf("%d\n", &T);
    bool pt;
    for(i=1;i<=T;i++) {
        printf("Case %d:",i);
        scanf("%s\n", comm);
        for(j=0;j<100;j++) bt[j]=0;
        for(j=p=0;comm[j];j++) {
            l=comm[j];
            
            if(l=='.') {}
            else if(l=='>') p++;
            else if(l=='<') p--;    
            else if(l=='+') bt[p]++;    
            else if(l=='-') bt[p]--;    
            if(p==100)p=0;
            else if(p==-1) p=99;

            if(bt[p]==256)bt[p]=0;
            else if(bt[p]==-1) bt[p]=255;
        }
        for(j=0;j<100;j++) {
            printf(" %02X",bt[j]);
        }
        puts("");        
        
    }
}

