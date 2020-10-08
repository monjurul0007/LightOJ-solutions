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

ll ar[20],n;
char mat[20][20];
ll dp[100000];

ll solve(int in, ll mask){
	ll &res = dp[mask];
	
	if(res != -1)
		return res;
	
	if(in >= n)
		return 0;
		
	res = LLONG_MAX;
	for(int i=0; i<n; i++){
		if(!(mask & (1 << i))){
			int mx = 1;
			for(int j=0; j<n; j++){
				if(mask & (1 << j)){
					mx = max(mx, (mat[j][i] - '0'));
				}
			}
			
			ll temp = solve(in+1, mask | (1 << i)) + ceil((double)ar[i]/mx);
			res = min(temp, res);
		}
	}
	
	return res;
}

int main(){
	//fasterInOut;
	
	int T;
	scanf("%d",&T);
	
	for(int t=1; t<=T; t++){
		scanf("%lld",&n);
		for(int i=0; i<n; i++)
			scanf("%lld",&ar[i]);
		for(int i=0; i<n; i++)
			scanf("%s",mat[i]);
		
		mem(dp,-1);
		printf("Case %d: %lld\n",t,solve(0,0));
		
	}
	
	
    return 0;
}

