#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MAX = 100000;
int f[MAX];
int main(){
  int t, n, ff;
  scanf("%d", &t);
  while(t--) {
    fill(f, f+MAX, 0);
    scanf("%d", &n);
    while (n--) {
      scanf(" %*s %d", &ff);
      f[ff]++;
    }
    int i, mi=0;
    for(i = 1;i < MAX;i++) {
      if(f[i] > f[mi]) mi=i;
    }
    printf("%d\n", mi);
  }
  return 0;
}
