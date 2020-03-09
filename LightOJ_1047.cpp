#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

int n;
ll r[25],g[25],b[25];
ll dp[25][4];

ll solve(int i, int state){
	if(dp[i][state] != -1)
		return dp[i][state];
		
	if(i >= n)
		return 0;
	
	if(state == 0){
		return min(min(solve(i,1),solve(i,2)),solve(i,3));
	}
	
	ll res1,res2;
	
	if(state == 1){
		res1 = r[i] + solve(i+1, 2);
		res2 = r[i] + solve(i+1, 3);
	}
	else if(state == 2){
		res1 = g[i] + solve(i+1, 1);
		res2 = g[i] + solve(i+1, 3);
	}
	else{
		res1 = b[i] + solve(i+1, 1);
		res2 = b[i] + solve(i+1, 2);
	}
	
	dp[i][state] = min(res1,res2);
	
	return dp[i][state];
}

int main(){
    //fasterInOut;
    int T;
    
    scanf("%d",&T);
    
    for(int t=1; t<=T; t++){
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%lld %lld %lld",&r[i],&g[i],&b[i]);
		}
		mem(dp,-1);
		
		printf("Case %d: %lld\n",t,solve(0,0));
	}
    
}
