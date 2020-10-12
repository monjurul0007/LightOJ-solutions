/*      bismillahir rahmanir rahim   
 *		     @ monjurul0007
 */


#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define F first
#define S second
#define mod 100000007

typedef long long int ll;    
typedef unsigned long long int ull;   
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};


int main(){
	
	int T;
	scanf("%d",&T);
	
	for(int t=1; t<=T; t++){
		ll s,l = 1,r = 1e8,x,y;
		scanf("%lld",&s);
		
		while(l <= r){
			ll mid = (l+r)/2;
			
			ll sum = 1 + mid*(mid-1);
	
			if(sum - mid+1 <= s && s <= sum + mid-1){
				x = mid;
				y = mid - abs(sum - s);
				
				if((s > sum && mid%2) || (s < sum && mid%2 == 0))
					swap(x,y);
					
				break;
			}
			
			if(sum > s)
				r = mid -1;
			else
				l = mid + 1;
		}
		
		if(s == 1){
			x = 1;
			y = 1;
		}
		
		printf("Case %d: %lld %lld\n",t,x,y);
	}
	
    return 0;
}

