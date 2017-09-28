#include <cstdio>
#include <cstring>

int main() {
    int T, soma, val;
    char op[20];
    scanf("%d\n", &T);
    soma=0;
    while(T--) {
        scanf("%s", op);
        if(strcmp(op,"donate")==0) {
            scanf("%d\n", &val);
            soma+=val;
        }
        else 
            printf("%d\n", soma);
    }
    return 0;
}
