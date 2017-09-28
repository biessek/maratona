#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MAX = 100001;
int arr[MAX], arr2[MAX];
map<int,int> pos;
vi comp[MAX];
bitset<MAX> V;
void dfs(int v, int c) {
    V[v] = true;
    comp[c].push_back(v);
    if(!V[pos[arr2[v]]]) {
      dfs(pos[arr2[v]], c);
    }
}

int main(){
  int n;
  int c=0;
  scanf("%d", &n);

  for(int i = 0; i< n; i++) {
    scanf("%d", &arr[i]);
    arr2[i] = arr[i];
    pos[arr[i]] = i;
  }
  sort(arr2, arr2+n);
  for(int i = 0; i < n; i++) {
    if(!V[i]) {
      dfs(i, c++);
    }
  }
  printf("%d\n", c);
  for(int i = 0; i < c; i++) {
    printf("%d", (int)comp[i].size());
    for(int j=0;j<(int)comp[i].size();j++) {
      printf(" %d", comp[i][j]+1);
    } puts("");
  }

  return 0;
}
