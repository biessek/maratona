#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<string,int> is;

int start, iend, max_so_far;
void maxSubArraySum(int a[], int size)
{
	start = iend = 0;
	max_so_far = INT_MIN;
    int max_ending_here = 0;
    int s=0;
 
    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here || (max_so_far == max_ending_here && (iend-start<i-s))) 
        {
            max_so_far = max_ending_here;
            start = s;
            iend = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i+1;
        }
    }    
}

int main() {
	int n, m;
	int a[20010];
	scanf("%d", &n);
	for(int k=0;k<n;k++) {
		scanf("%d", &m);	
		for(int i=0;i<m-1;i++) {
			scanf("%d", &a[i]);	
		}	
		maxSubArraySum(a, m-1);		
		if(max_so_far < 0) {
			printf("Route %d has no nice parts\n", k+1);
		} else {
			printf("The nicest part of route %d is between stops %d and %d\n", k+1, start+1, iend+2);			
		}
	}

	return 0;
}
