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

int n1,n2,n3;
char s1[55],s2[55],s3[55];
ll dp[55][55][55];

ll solve(int i, int j, int k){
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
		
	if(i >= n1 || j >= n2 || k >= n3)
		return 0;
		
	if(s1[i] == s2[j] && s2[j] == s3[k]){
		return dp[i][j][k] = 1 + solve(i+1, j+1, k+1);
	}
	
	ll res1, res2, res3;
	res1 = solve(i+1, j, k);
	res2 = solve(i, j+1, k);
	res3 = solve(i, j, k+1);
	
	return dp[i][j][k] = max(res1, max(res2, res3));
}

int main(){
	//fasterInOut;
	
	int t;
	scanf("%d",&t);
	for(int T=1; T<=t; T++){
		scanf("%s",s1);
		scanf("%s",s2);
		scanf("%s",s3);
		n1 = strlen(s1);
		n2 = strlen(s2);
		n3 = strlen(s3);
		
		mem(dp, -1);
		printf("Case %d: %lld\n",T,solve(0,0,0));
	}	
	
    return 0;
}
