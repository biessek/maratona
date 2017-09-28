#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<string>
using namespace std;
char st[200010];
std::string a,b;
int main() {
    int i, j;
    while(gets(st)) {
        
        i=0; j = strlen(st)-1;        
        if(j == 3 && st[0] == 'D' && st[1] == 'O' && st[2] == 'N' && st[3] == 'E') break;

        a=b="";

        for(i=0;i<=j;i++) if(isalpha(st[i])) a+=toupper(st[i]);    
        b=a;    
        reverse(a.begin(),a.end());
        j=a.length();

        for(i=0;i<=j;i++) if(a[i]!=b[i]) break;    
        
        if(i>j) printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }    

    return 0;
}
