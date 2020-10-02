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

ll mat[20][20],n;
ll dp[100000];

ll solve(int in, ll mask){
	ll &res = dp[mask];
	
	if(res != -1)
		return res;
		
	if(in >= n)
		return 0;
	
	res = 0;	
	for(int i=0; i<n; i++){
		if(!(mask & (1 << i))){
			res = max(solve(in+1, mask | (1 << i)) + mat[in][i], res);
		}
	}
	
	return res;
}

int main(){
	int t;
	scanf("%d",&t);
	
	for(int T=1; T<=t; T++){
		scanf("%lld",&n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%lld",&mat[i][j]);
		
		mem(dp, -1);
		printf("Case %d: %lld\n",T,solve(0,0));
	
	}
	
    return 0;
}

