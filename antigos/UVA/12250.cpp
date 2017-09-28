#include <cstdio>
#include <cstring>

    char *alf[] = { "HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"   };
    char *lan[] = { "ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};

int main() {
    int i, t=1;
    char in[20];
    while(scanf("%s\n", in) && strcmp(in,"#") != 0) {
    
        for(i=0;i<6;i++) {
            if(strcmp(in,alf[i])==0) break;
        }
        if(i!=6) printf("Case %d: %s\n",t++,lan[i]);
        else printf("Case %d: %s\n",t++,"UNKNOWN");
    }

    return 0;
}
