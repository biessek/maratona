#include<cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    map<string,int> assassinos;//NOME E QTD QE MATOU
    map<string,bool> assassino_st;//NOME E STATUS (VIVO OU MORTO)
    char na[12], nv[12];
     
    while(scanf(" %s %s",na,nv)!=EOF){
        assassino_st[string(nv)] = true;
        assassinos[string(na)]++;
    }       
    puts("HALL OF MURDERERS");
    for(map<string,int>::iterator it=assassinos.begin();it != assassinos.end();it++) {
        if(assassino_st.find(string((*it).first)) == assassino_st.end())
            printf("%s %d\n",(*it).first.c_str(),(*it).second);
    }
}
