#include <bits/stdc++.h>
using namespace std;
const unsigned MAX = 100001;

const unsigned edo[] = {2,2,1,2,2,2,1};

int main() {
    unsigned n, e[MAX], nota, notaesc;
    unsigned i,j, k;
    
    scanf("%u", &n);
    for (i = 0; i < n; i++) {
        scanf("%u", &e[i]);
    }

    for (i = 0; i < 12; i++) {
        bool esc = true;
        for (j = 0; esc && j < n; j++) {
            nota = (e[j]-1) % 12;
            for (k = 0, notaesc=i; k < 7; notaesc = (notaesc+edo[k])%12, k++) {
                if(nota == notaesc) break;
            }
            if(k == 7) { // n esta na escala
                esc = false;
            }
        }
        if(esc) {
            const char* nomes[12] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
            puts(nomes[i]);
            break;
        }
    }
    
    if(i==12) {
        puts("desafinado");
    }
    return 0;	
}