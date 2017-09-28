#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
char p[30];
map<char, char> mapa;
void prepare() {
    mapa.clear();
    mapa['A']='A';	
    mapa['E']='3';
    mapa['H']='H';
    mapa['I']='I';
    mapa['J']='L';
    mapa['L']='J';
    mapa['M']='M';
    mapa['O']='O';
    mapa['S']='2';
    mapa['T']='T';
    mapa['U']='U';
    mapa['V']='V';
    mapa['W']='W';
    mapa['X']='X';
    mapa['Y']='Y';
    mapa['Z']='5';
    mapa['1']='1';
    mapa['2']='S';
    mapa['3']='E';
    mapa['5']='Z';
    mapa['8']='8';
}

bool ispal() {
    int i, j, t;
    i=0;
    t = strlen(p);   
    j=t-1;
    while(i<j && i<t&&j>-1) {if(p[i]!=p[j]) return false; i++;j--;}

    return true;

}   

bool ismir() {
    int i, j, t;
    t = strlen(p);   
    i=0;
    j=t-1;
    while(i<=j && i<t&&j>-1) {
        if(mapa.find(p[i]) == mapa.end()) return false;
        if(mapa[p[i]]!=p[j]) return false;
        i++;j--;

    }
    
    return true;
}   

int main() {
    prepare();
    int i, j;
    bool isp,ism; 
    while(scanf(" %s", p) != EOF) {
        isp = ispal();
        ism = ismir();
        if(isp&&ism)       
            printf("%s -- is a mirrored palindrome.\n", p);
        else if(!isp && ism)       
            printf("%s -- is a mirrored string.\n", p);
        else if(!ism && isp)       
            printf("%s -- is a regular palindrome.\n", p);
        else
            printf("%s -- is not a palindrome.\n", p);
        puts("");
    }
    return 0;
}
