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
char s[1005];
int dp[1005][1005];
ll mainDp[1005];

bool findPle(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
	
	if(i >= j)
		return true;
		
	if(s[i] == s[j])
		dp[i][j] = findPle(i+1, j-1);
	else
		dp[i][j] = false;
	
	return dp[i][j];
}

ll solve(int i){
	if(mainDp[i] != -1)
		return mainDp[i];
		
	if(i >= n)
		return 0;
	
	ll res,ans = 1 + solve(i+1);
	
	for(int k=i+1; k<n; k++){
		if(findPle(i,k))
			res = 1;
		else
			res = (k - i + 1);
			
		res += solve(k+1);
		
		ans = min(ans, res);
	}
	
	return mainDp[i] = ans;
}

int main(){
	//fasterInOut;
	
	int t;
	scanf("%d",&t);
	for(int T=1; T<=t; T++){
		scanf("%s",s);
		n = strlen(s);
		mem(dp,-1);
		mem(mainDp,-1);
		printf("Case %d: %lld\n",T,solve(0));
	}	
	
    return 0;
}
