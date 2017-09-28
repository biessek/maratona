#include <cstdio>

int main () {
    int n, l, h;
    char guess[30];
    l=1;h=10;
    while(scanf("%d ", &n) && n) {
//        getchar();
        scanf("%[^\n]\n", guess);
        if(guess[0] == 'r') {
            if(l<=h && n>=l&&n<=h) puts("Stan may be honest");
            else puts("Stan is dishonest");
            l=1; h=10;
        } else if(guess[4] == 'h' && n <= h) {
            h=n-1;
        } else if(guess[4] == 'l' &&  n >= l)
            l=n+1;   
    }

}
