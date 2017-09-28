#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

int ct[26];
int p[2000][26];
char ps[2000][23];
char s[30];

void c(int j, int ctt[26], int us[21], int ku) {
    if(j==-1) return;
    int i;

    int ncu[26], ncu2[26];

    for(i=0;i<26;i++) {
        ncu[i]=ncu2[i]=ctt[i];
    } 

    c(j-1, ncu, us, ku);

    bool finito=true;
    for(i=0;i<26;i++) {        
        ncu2[i]=ncu2[i]-p[j][i];
        finito&=ncu2[i]==0;
        if(ncu2[i]<0) return;
    }

    if(finito) {     

        printf("%s", ps[j]);

        for(i=1;i<=ku;i++) {
            printf(" %s", ps[us[i]]);  
        } puts("");
        return;
    }

    int nus[21];

    for(i=0;i<ku;i++) nus[i]=us[i];
    nus[++ku]=j;

    c(j-1,ncu2,nus,ku);
}



int main() {
    int t, i, j=0;
    int us[21];

    while(gets(ps[j]) && ps[j][0]!='#') {
        t = strlen(ps[j])-1;
        
        memset(p[j],0,sizeof(p[j]));

        for(i=0;i<t;i++) {
            p[j][ps[j][i]-'A']++;
        }

        j++;
    } 

    while(gets(s) && s[0]!='#') {

        t = strlen(s)-1;
        memset(ct,0,sizeof(ct));

        for(i=0;i<t;i++) {
            if(s[i] >= 'A' && s[i] <= 'Z')
            ct[s[i]-'A']++;
        }        
        c(j-1,ct, us, 0);
    }         

    return 0;
}
