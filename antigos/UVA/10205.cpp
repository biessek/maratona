#include <cstdio>

#include <cstring>



int s[101][53];

int d[53];

int nd[53];

char inp[50];



char card[15][15]={"","2","3","4","5","6","7","8", "9","10", "Jack", "Queen", "King","Ace"};

char sign[5][10]={"Clubs", "Diamonds", "Hearts", "Spades"};





int main() {

    bool f=false;

    int n, t, i, j, shufle;

    scanf("%d", &t);



    while(t--) {

        if (f) puts("");

        f=true;

        scanf("%d", &n);

        for(i=1;i<=n;i++) {    

            for(j=1;j<=52;j++) {       

                scanf("%d", &s[i][j]);

            }
        }
        getchar();

        for(i=1;i<=52;i++) d[i]=i;
        while(gets(inp) && strlen(inp)){
            sscanf(inp, "%d", &shufle);
 
            for(i=1;i<=52;i++) {
                nd[i] = d[s[shufle][i]];       
            }

            for(i=1;i<=52;i++) {
                d[i]=nd[i];
            }            
        }

        for(i=1;i<=52;i++) {
            printf("%s of %s\n",card[((d[i]-1)%13)+1], sign[(d[i]-1)/13]);
        }        

    }





    return 0;

}
