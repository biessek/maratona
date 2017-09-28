#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAX = 1001;
int main(){
  char s[MAX];
  int c[26];
  int k;
  scanf(" %s %d", s, &k);
  int t = strlen(s);
  if(t < k) {
    puts("impossible");
    return 0;
  }

  fill(c, c+26, 0);
  for(int i = 0;i < t;i++) {
    c[s[i]-'a']++;
  }
  for(int i = 0;i < 26;i++) {
    if(c[i]!= 0) {
      k--; t--;
    }
  }
  printf("%d\n", max(0,min(k, t)));
  return 0;
}
