#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;

ll c[1000001];

ll gcd(ll a, ll b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

ll lcm(ll a, ll b)
{
    ll temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main() {
    ll n, L;
    scanf("%llu %llu", &n, &L);
    ll tes = 1;
    for (ll i = 0; i < n; i++) {
        scanf("%llu", &c[i]);    
        tes = lcm(tes, c[i]);
    }
    ll maximo = 0;
    ll imax;
    
    for (ll i = 0; i < 1000000; i++) {
        ll cc = lcm(tes,i);
        if(cc>maximo && cc <= L) {
            maximo = cc;
            imax = i;
        } 
    }
    printf("%llu\n", imax);
    return 0;	
}