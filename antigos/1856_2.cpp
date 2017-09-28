#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<list>
#include<vector>
// #include<vector>
using namespace std;
int main() {
    printf("50000\n1");
    for(int i=2;i<=50000;i++) {
        printf(" %d",i);
    }
    printf("\n%d\n",351+351);
    for(int i=49351;i<=49700;i++) {
        printf("R %d\n",i);
    }
    printf("Q %d %d\n",50000,49701);
    int ant=50000;
    for(int i=49351;i<=49700;i++) {
        printf("I %d %d\n",i, ant);
        ant=i;
    }
    printf("Q %d %d\n",50000,49701);
    return 0;
}