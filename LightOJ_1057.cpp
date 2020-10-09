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

char mat[25][25];
int dis[20][20];
ll dp[17][1 << 17];
int num;

ll solve(int in, int j, ll mask){
	ll &res = dp[j][mask];
	
	if(res != -1)
		return res;
	
	if(in >= num)
		return dis[j][0];
	
	res = LLONG_MAX;
	for(int i=1; i<num; i++){
		if(!(mask & (1<<i))){
			res = min(solve(in+1, i, mask | (1<<i)) + dis[i][j] , res); 
		}
	}
	
	return res;	
}

int main(){
	//fasterInOut;
	
	int T;
	scanf("%d",&T);
	
	for(int t=1; t<=T; t++){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0; i<n; i++)
			scanf("%s",mat[i]);
		
		vector <pii> v;
		for(int i=0; i<n && !v.size(); i++)
			for(int j=0; j<m; j++)
				if(mat[i][j] == 'x'){
					v.pb({i,j});
					break;
				}
		
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(mat[i][j] == 'g')
					v.pb({i,j});
				
		num = v.size();	
		
		for(int i=0; i<num; i++)
			for(int j=i+1; j<num; j++)
				dis[i][j] = dis[j][i] = max(abs(v[i].F-v[j].F) ,abs(v[i].S-v[j].S));
		
		mem(dp, -1);
		
		printf("Case %d: %lld\n",t,solve(1,0,0));
		
	}
	
	
    return 0;
}

