#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
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
char s[105];
ll dp[105][105];

ll solve(int st, int en){
	if(dp[st][en] != -1)
		return dp[st][en];
		
	if(st >= en)
		return 0;
		
	ll res1 = 0, res2 = 0;
	if(s[st] == s[en]){
		dp[st][en] = solve(st+1, en-1);
		return dp[st][en];
	}
	
	res1 = 1 + solve(st, en-1);
	res2 = 1 + solve(st+1, en);
	
	return dp[st][en] =  min(res1,res2);
}

int main(){
	//fasterInOut;
	
	int t;
	scanf("%d",&t);
	for(int T=1; T<=t; T++){
		scanf("%s",s);
		n = strlen(s);
		mem(dp, -1);
		printf("Case %d: %lld\n",T,solve(0,n-1));
	}	
	
    return 0;
}
