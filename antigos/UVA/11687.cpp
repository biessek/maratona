#include<cstdio>
#include<cstring>

char num[1000005];
int tam;

int cd(int x) {
    int res=1;
    while(x>=10) {
        res++;
        x/=10;
    }
    return res;
}

int main() {
    int x,i,xant;
    while(scanf("%s\n", num) && num[0]!='E') {
        tam=strlen(num);

        xant = tam==1&&num[0]=='1'? 1 : -1;
        x=tam; 
        i=0;
        while(x!=xant) {
            i++;
            xant=x;
            x=cd(xant);
        }    
        printf("%d\n",i+1);
    }
    
    return 0;
}
