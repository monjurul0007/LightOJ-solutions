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
char s[65];

ll dp[65][65];

ll solve(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
		
	if(j < i || i >=n || j < 0)
		return 0;
	
	ll res;
	
	if(s[i] == s[j])
		res = (1 + solve(i+1, j-1) +(solve(i+1, j) + solve(i, j-1) - solve(i+1, j-1)));
	else
		res = solve(i+1, j) + solve(i, j-1) - solve(i+1, j-1);
	
	dp[i][j] = res;
	
	return res;
}

int main(){
	///fasterInOut;
	
	int T;
	
	scanf("%d",&T);
	
	for(int t=1; t<=T; t++){
		scanf("%s",s);
		n = strlen(s);
		
		mem(dp, -1);
		printf("Case %d: %lld\n",t,solve(0,n-1));
		
	}
			
    return 0;
}
