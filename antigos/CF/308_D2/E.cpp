#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    char s[6000], l;
    int i;
    int cs=0, k;    
    long long sum[15*3];
    scanf("%s", s);
    for(k=15*3-1;k>=0;k--) {
        sum[k]= s[0]-'0';
    }
    for(i=1;s[i];i+=2) {
        if(l == '*') { // dec
            sum[cs] += - (s[i-1]-'0') + ((s[i-1]-'0') * (s[i+1]-'0'));
            sum[cs+1] += - (s[i-1]-'0') + ((s[i-1]-'0') * (s[i+1]-'0'));

            if(cs > 0) {
                sum[cs+2] += - (s[i-1]-'0') - (s[i-3]-'0') + ((s[i-1]-'0'+s[i-3]-'0') * (s[i+1]-'0'));
            }
            cs+=3;
        } else if(l == '+'){
            for(k=cs-1;k>=0;k--) {
                sum[k]+= s[i+1]-'0';
            }
        }
    }
    printf("%lli\n",sum+n);

}
