#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef set<char> si;
char P[4][10] = {"he", "she", "his", "hers"};; //keyw
int K = 4; //qt keyw
char allP[60]; //keyw

vi T[60]; // sum keyw sizes;
int go[60][26];
map<int,int> out;

int main() {
	int c,i,j,k;
	int idx=1;
	allP[0] = '0';
	out.clear();
	for(i=0;i<26;i++) go[0][i]=0; // minusc
	for(i=0;i<K;i++) {
		c=0;
		for(j=0;P[i][j];j++,idx++) {			
			allP[idx] = P[i][j];
			bool f=false;
			for(k=0;k<T[c].size();k++) {
				if(allP[T[c][k]] == P[i][j]) {
					go[0][P[i][j]-'a']=c;
					c = T[c][k]; 
					f=true;
					break;
				}
			}
			if(!f) {
				break;
			}
		}
		while(P[i][j]) {
			allP[idx] = P[i][j];
			T[c].push_back(idx);
			c = idx;
			idx++;
			j++;
		}
		out[c] = i;
		T[c].push_back(0);
	}
	
	
	return 0;
}
