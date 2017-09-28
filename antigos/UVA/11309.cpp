#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>

char L[10];
bool p[2500];

bool isp() {
    int i=0;
    int j= strlen(L)-1;

    while(i<j&&L[i]==L[j]) { i++; j--; }

    return i >= j;
}

void c() {
    int i=0;
    for(i=0;i<=2400;i++) {
        sprintf(L,"%d",i);
        p[i]=isp();
    }
}

int main() {
    c();
    int t, h, m;
    scanf("%d\n", &t);
    while(t--) {
        scanf("%d:%d\n", &h, &m);    
        h = h * 100 + m;
        if(h%100 >=60) h = h / 100 * 100 + 100; // aumenta a hora;
        h++;
        while(true) {
            if(h%100 >=60) h = h / 100 * 100 + 100; // aumenta a hora;
            
            if(h<=2359) {
                if(p[h]) break;
            } else { h=0; break;}           
            h++;
        }
        printf("%02d:%02d\n", h / 100, h % 100);
    }

    return 0;
}
