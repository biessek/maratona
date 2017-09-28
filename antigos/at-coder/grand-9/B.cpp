#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main() {
    ll c[26];
    char txt[200002];
    scanf(" %s", txt);
    ll t = strlen(txt);
    fill(c,c+26,0);
    for(int i = 0;i<t;i++) c[txt[i]-'a']++;
    ll r = (t * (t-1)) >> 1;
    ll s = 0;
    for(int i = 0;i<26;i++) {
      s += (c[i] * (c[i]-1) )>> 1;
    }
    printf("%lli\n", 1 + (r-s));
    return 0;
}
