#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MAX = 100000;

int main(){
  int t, a, b, c;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d %d", &a, &b, &c);
    if(a < b && a < c) puts("First");
    else if(a > b && b < c) puts("Second");
    else puts("Third");
  }
  return 0;
}
