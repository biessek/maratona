#include <cstdio>
#include <cstring>

int main() {
    int t, c;
    char num[20];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", num);
        if(strlen(num) > 3) puts("3");
        else {
            c=num[0]=='t'; c+= num[1]=='w'; c+= num[2]=='o';
            if(c>=2) puts("2");   
            else puts("1");
        }
        
    }

    return 0;
}
