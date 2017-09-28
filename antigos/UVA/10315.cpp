#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef struct {char V,N;} card;
#define FL 1
#define FH 2
#define FK 4
#define FLUSH 8
#define STRAIGHT 16
#define TK 32
#define OP 64
#define TP 128

    card h[2][5];    

map<char,int> mc;
map<char,int> ms;
int sp[2];
int spp[2];

bool ss(int i) {
    return h[i][0].N == h[i][1].N && 
           h[i][1].N == h[i][2].N &&
           h[i][2].N == h[i][3].N &&
           h[i][3].N == h[i][4].N;
}
bool st(int i) {
    return h[i][0].V == h[i][1].V-1 && 
           h[i][1].V == h[i][2].V-1 &&
           h[i][2].V == h[i][3].V-1 &&
           h[i][3].V == h[i][4].V-1;
}
bool fk(int m) {
    int ct;
    for(int i=0;i<2;i++) {
        ct=1;
        for(int j=i+1;j<5 && ct < 4;j++) {
            if(h[m][j].V==h[m][i].V) ct++;
        }
        if(ct==4) {
            sp[m]=i;
            return true;                
        }
    }
    return false;
}

bool fh(int m) {
    int ct, i, j;
    for(i=0;i<3;i++) {
        ct=1;
        for(j=i+1;j<5 && ct < 3;j++) {
            if(h[m][j].V==h[m][i].V) ct++;
        }
        if(ct==3) {
            sp[m]=i;
            return h[m][j%5].V == h[m][(j+1)%5].V;
        }
    }
    return false;
}

bool tk(int m) {
    int ct, i, j;
    for(i=0;i<3;i++) {
        ct=1;
        for(j=i+1;j<5 && ct < 3;j++) {
            if(h[m][j].V==h[m][i].V) ct++;
        }
        if(ct==3) return true;
    }    
    return false;
}

bool tp(int m) {
    int ct=0, i;
    for(i=0;i<4&&ct<2;i++) {
        if(h[m][i].V==h[m][i+1].V) {
            if(ct) spp[m] = i;
            else sp[m] = i;
            ct++;
            i++;
        }
    }    
    return ct>=2;
}

bool op(int m) {
    int ct, i;
    for(i=0;i<4;i++) {
        if(h[m][i].V==h[m][i+1].V) { sp[m] = i; return true; }
    }    
    return false;
}

int comp() {
    int ph[2];
    int i;
    ph[0]=0;
    ph[1]=0;

    if(ss(0)) ph[0]|=FLUSH;    
    if(st(0)) ph[0]|=STRAIGHT;    
    if(ss(1)) ph[1]|=FLUSH;    
    if(st(1)) ph[1]|=STRAIGHT;    

    if((ph[0] & FLUSH) && (ph[0] & STRAIGHT) &&
       (ph[1] & FLUSH) && (ph[1] & STRAIGHT)) {
//        printf("sfdois\n");
        i=4;
        if(mc[h[0][i].V] > mc[h[1][i].V]) return 1;
        if(mc[h[0][i].V] < mc[h[1][i].V]) return 2;
        return 0;
    }
    if((ph[0] & FLUSH) && (ph[0] & STRAIGHT)) {
//        printf("sf 1\n");
       return 1;
    }
    if((ph[1] & FLUSH) && (ph[1] & STRAIGHT)) {
//        printf("sf 2\n");
        return 2;
    }
    
    if(fk(0)) ph[0]|=FK;    
    if(fk(1)) ph[1]|=FK;    

    if((ph[0] & FK) && (ph[1] & FK)) {
//        printf("fk dois\n");
        int i1, i2;
        i1=sp[0];
        i2=sp[1];
        if(mc[h[0][i1].V]>mc[h[1][i2].V]) return 1;
        if(mc[h[0][i1].V]<mc[h[1][i2].V]) return 2;
        return 0;
    } else if(ph[0] & FK) {
//        printf("fk 1\n");
        return 1;
    } else if(ph[1] & FK) {
//        printf("fk 2\n");
        return 2;
    }

    
    if(fh(0)) ph[0]|=FH;    
    if(fh(1)) ph[1]|=FH;    

    if((ph[0] & FH) && (ph[1] & FH)) {
//        printf("fh dois\n");
        int i1, i2;
        i1=sp[0];
        i2=sp[1];
        if(mc[h[0][i1].V]>mc[h[1][i2].V]) return 1;
        if(mc[h[0][i1].V]<mc[h[1][i2].V]) return 2;
        return 0;
    } else if(ph[0] & FH) {
//        printf("fh 1\n");
        return 1;
    } else if(ph[1] & FH) {
//        printf("fh 2\n");
        return 2;
    }

    if((ph[0] & FLUSH) && (ph[1] & FLUSH)) {
//        printf("flush\n");
        i=4;
        while(i>=0) {
            if(mc[h[0][i].V]>mc[h[1][i].V]) return 1;
            if(mc[h[0][i].V]<mc[h[1][i].V]) return 2;
            i--;
        }
        return 0;
    } else if(ph[0] & FLUSH) {
//        printf("flush 1\n");
        return 1;
    } else if(ph[1] & FLUSH) {
//        printf("flush 2\n");
        return 2;
    }

    if((ph[0] & STRAIGHT) && (ph[1] & STRAIGHT)) {
//        printf("str\n");
        i=4;
        if(mc[h[0][i].V]>mc[h[1][i].V]) return 1;
        if(mc[h[0][i].V]<mc[h[1][i].V]) return 2;
        return 0;
    } else if(ph[0] & STRAIGHT) {
//        printf("str 1\n");
        return 1;
    } else if(ph[1] & STRAIGHT) {
//        printf("str 2\n");
        return 2;
    }

    if(tk(0)) ph[0]|=TK;            
    if(tk(1)) ph[1]|=TK;            

    if((ph[0] & TK) && (ph[1] & TK)) {
        int i1, i2;
        i1=sp[0];
        i2=sp[1];
        if(mc[h[0][i1].V]>mc[h[1][i2].V]) return 1;
        if(mc[h[0][i1].V]<mc[h[1][i2].V]) return 2;
        return 0;
    } else if(ph[0] & TK) {
        return 1;
    } else if(ph[1] & TK) {
        return 2;
    }
    
    if(tp(0)) ph[0]|=TP;            
    if(tp(1)) ph[1]|=TP;            
    
    if((ph[0] & TP) && (ph[1] & TP)) {
        int i1, i2;
        i1=spp[0];
        i2=spp[1];
        if(mc[h[0][i1].V]>mc[h[1][i2].V]) return 1;
        if(mc[h[0][i1].V]<mc[h[1][i2].V]) return 2;
        i1=sp[0];
        i2=sp[1];
        if(mc[h[0][i1].V]>mc[h[1][i2].V]) return 1;
        if(mc[h[0][i1].V]<mc[h[1][i2].V]) return 2;

        for(i=0;i<5;i++) { if(i!=spp[0] && i!=spp[0]+1 && i!=sp[0] && i!=sp[0]+1) {i1=i; break; }}
        for(i=0;i<5;i++) { if(i!=spp[1] && i!=spp[1]+1 && i!=sp[1] && i!=sp[1]+1) { i2=i; break; }}
//        printf("a %d %d\n",i1, i2);
        if(mc[h[0][i1].V]>mc[h[1][i2].V]) return 1;
        if(mc[h[0][i1].V]<mc[h[1][i2].V]) return 2;        
        return 0;
    } else if(ph[0] & TP) {
        return 1;
    } else if(ph[1] & TP) {
        return 2;
    }

    if(op(0)) ph[0]|=OP;            
    if(op(1)) ph[1]|=OP;            


    if((ph[0] & OP) && (ph[1] & OP)) {
        int i1, i2;
        i1=sp[0];
        i2=sp[1];
        if(mc[h[0][i1].V]>mc[h[1][i2].V]) return 1;
        if(mc[h[0][i1].V]<mc[h[1][i2].V]) return 2;
        i=4;
        while(i>=0) {
    //        printf("t...\n");
    //        printf("%c %c\n",h[0][i].V,h[1][i].V);
            if(mc[h[0][i].V]>mc[h[1][i].V]) return 1;
            if(mc[h[0][i].V]<mc[h[1][i].V]) return 2;
            i--;
        }
    } else if(ph[0] & OP) {
        return 1;
    } else if(ph[1] & OP) {
        return 2;
    }
    i=4;
    while(i>=0) {
//        printf("t...\n");
//        printf("%c %c\n",h[0][i].V,h[1][i].V);
        if(mc[h[0][i].V]>mc[h[1][i].V]) return 1;
        if(mc[h[0][i].V]<mc[h[1][i].V]) return 2;
        i--;
    }
    return 0;
    
}

void mmvc() {
    mc.clear();
    ms.clear();
    mc['2']=2;  mc['3']=3;  mc['4']=4;  mc['5']=5;  mc['6']=6; mc['7']=7; mc['8']=8; mc['9']=9;
    mc['T']=10; mc['J']=11; mc['Q']=12; mc['K']=13; mc['A']=14;

    ms['C']= 1; ms['D']= 2; ms['H']= 3; ms['S']= 4;
}

bool csort(const card &a,const card &b) {
    return mc[a.V] == mc[b.V]? ms[a.N] < ms[b.N] : mc[a.V] < mc[b.V];
}

int main() {
    int i,j;
    char d[100], N,V;
    mmvc();
    while(gets(d)) {
        for(i=j=0;i<10;i++,j+=3) {
            V=d[j]; 
            N=d[j+1];
            h[i/5][i%5].V = V;
            h[i/5][i%5].N = N;
        }

        sort(h[0],h[0]+5,csort);
        sort(h[1],h[1]+5,csort);
//        for(i=j=0;i<10;i++,j+=3) {
//            printf("%c%c ", h[i/5][i%5].V, h[i/5][i%5].N);
//        } puts("");

        int r= comp();
        if(r==0) puts("Tie.");
        else if(r==1) puts("Black wins.");
        else    puts("White wins.");
        
    }

    return 0;
}
