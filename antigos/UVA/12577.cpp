#include <cstdio>
#include <cstring>

int main() {
    char op[20];
    int t=1;
    while(scanf("%s", op) && op[0]!='*') {
        printf("Case %d: ", t++);
        if(strcmp(op,"Hajj")==0) {
            puts("Hajj-e-Akbar");
        } else {
            puts("Hajj-e-Asghar");
        }
    }
    return 0;
}
