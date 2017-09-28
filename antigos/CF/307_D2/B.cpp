#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int a[30], b[30], c[30];
char A[500002], B[500002], C[500002], O[2][500005];
int to[2], r[2];

void        test(int i, int[] a,int[] b,int[] c, int minC, int minB ) {
    if(i==0) {
        for(i=0;i<26;i++) {
            a[i] -= (b[i]*minB);
        }   
        while(minB--) {
            to += lb;
            strcat(O,B);
        }

        minC = 600000;
        for(i=0;i<26;i++) {
            if(c[i] != 0)
                minC=min(minC,a[i]/c[i]);        
        }
        if(minC > 0 && minC < 600000) {
            for(i=0;i<26;i++) {
                a[i] -= (c[i]*minC);
            }   
            while(minC--) {
                to += lc;
                strcat(O,C);
            }
        }


    }
}

int main() {
    int i, l, minB, minC,  lb,lc ;
    for(i=0;i<26;i++) {
        a[i]=b[i]=c[i]=0;
    }
    scanf("%s\n", A);    l = strlen(A);
    for(i=0;i<l;i++) {
        a[A[i]-'a']++;
    }

    scanf("%s\n", B);    lb = strlen(B);
    for(i=0;i<lb;i++) {
        b[B[i]-'a']++;
    }    
    bool canb=true;
    for(i=0;i<26;i++) {
        if(a[i] < b[i])
            canb=false;
    }
    minB = 600000;
    if(canb) {  // how much b
        for(i=0;i<26;i++) {
            if(b[i] != 0)
                minB=min(minB,a[i]/b[i]);        
        }
    }

    scanf("%s\n", C);    lc = strlen(C);
    for(i=0;i<lc;i++) {
        c[C[i]-'a']++;
    }    

    bool canc=true;
    for(i=0;i<26;i++) {
        if(a[i] < c[i])
            canc=false;
    }
    minC = 600000;
    if(canc) {  // how much c
        for(i=0;i<26;i++) {
            if(c[i] != 0)
                minC=min(minC,a[i]/c[i]);        
        }
    }
    O[0][0]='\0'; to[0]=0;
    if(canb) {
        test(0,a,b,c);
    }

    
    if((canc && !canb) || (canc&&minC <= minB)) {        
        
        for(i=0;i<26;i++) {
            a[i] -= (c[i]*minC);
        }   
        while(minC--) {
            to += lc;
            strcat(O,C);
        }
        
        minB = 600000;
        for(i=0;i<26;i++) {
            if(b[i] != 0)
                minB=min(minB,a[i]/b[i]);        
        }
        if(minB > 0 && minB < 600000) {
            for(i=0;i<26;i++) {
                a[i] -= (b[i]*minB);
            }   
            while(minB--) {
                to += lb;
                strcat(O,B);
            } 
        }
    } else if((canb&&!canc)|| (canb&&minB <= minC)){
        for(i=0;i<26;i++) {
            a[i] -= (b[i]*minB);
        }   
        while(minB--) {
            to += lb;
            strcat(O,B);
        }

        minC = 600000;
        for(i=0;i<26;i++) {
            if(c[i] != 0)
                minC=min(minC,a[i]/c[i]);        
        }
        if(minC > 0 && minC < 600000) {
            for(i=0;i<26;i++) {
                a[i] -= (c[i]*minC);
            }   
            while(minC--) {
                to += lc;
                strcat(O,C);
            }
        }
    }  
    for(i=0;i<26;i++) {
        while(a[i]--) {
            O[to++]='a'+i;
        }
    }   
    O[to]='\0';   
    puts(O);
    
    return 0;
}
